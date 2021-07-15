package pkg06714;

import java.io.*;
import java.util.*;

class Main {
    public ProgramQueue ready = new ProgramQueue(), 
	blocked = new ProgramQueue();
    public int var[] = new int[26];
    public boolean isBlocked;

    private int timeQuant;

    private Statement readOneProgram (Scanner s, int pId) {
	Statement first = null, last = null, st = null;

	do {
	    switch (s.curSy) {
	    case Scanner.VARSY:    st = AssignStm.read(s,pId);  break;
	    case Scanner.PRINTSY:  st = PrintStm.read(s,pId);   break;
	    case Scanner.LOCKSY:   st = LockStm.read(s,pId);    break;
	    case Scanner.UNLOCKSY: st = UnlockStm.read(s,pId);  break;
	    case Scanner.ENDSY:    st = EndStm.read(s,pId);     break;
	    default:               System.err.println("** Compile error **");
		                   System.exit(2);
	    }

	    if (first == null) first = last = st;
	    else  	       last.next = last = st;
	} while (!(st instanceof EndStm));
	return first;
    }

    public void readPrograms () throws Exception {
	Scanner s = new Scanner();
	int nPrograms = s.curNum;  s.nextToken();

	AssignStm.execTime = s.curNum;  s.nextToken();  
	PrintStm.execTime  = s.curNum;  s.nextToken();
	LockStm.execTime   = s.curNum;  s.nextToken();
	UnlockStm.execTime = s.curNum;  s.nextToken();
	EndStm.execTime    = s.curNum;  s.nextToken();

	timeQuant = s.curNum;  s.nextToken();
	for (int i = 1;  i <= nPrograms;  ++i) 
	    ready.add(readOneProgram(s,i));
    }

    public void runPrograms () throws Exception {
	for (int i = 0;  i < 26;  ++i) var[i] = 0;
	isBlocked = false;

	while (! ready.isEmpty()) {
	    int clock = 0;
	    Statement st = ready.get();
	    do {
		clock += st.time();  st = st.run(this, System.out);
	    } while (clock<timeQuant && st!=null);
	    if (st != null) ready.add(st);
	}
    }

    public static void main (String arg[]) throws Exception {
	Main p = new Main();
	p.readPrograms();  p.runPrograms();
    }
}


class Scanner {
    public static final int NUMSY = 1, VARSY = NUMSY+1, EQSY = VARSY+1,
	LOCKSY = EQSY+1, UNLOCKSY = LOCKSY+1, PRINTSY = UNLOCKSY+1,
	ENDSY = PRINTSY+1;
    public int curSy, curNum;
    public String curVar;

    private StreamTokenizer s;
    private static final boolean DEBUG = false;

    Scanner () throws Exception {
	s = new StreamTokenizer(new InputStreamReader(System.in));
	s.eolIsSignificant(false);
	nextToken();
    }

    void nextToken () {
	try {
	    s.nextToken();
	    if (s.ttype == s.TT_NUMBER) {
		curSy = NUMSY;  curNum = (int)s.nval;
	    } else if (s.ttype == s.TT_WORD) {
		if (s.sval.equals("end")) curSy = ENDSY; 
		else if (s.sval.equals("lock")) curSy = LOCKSY;
		else if (s.sval.equals("print")) curSy = PRINTSY;
		else if (s.sval.equals("unlock")) curSy = UNLOCKSY;
		else { curSy = VARSY;  curVar = s.sval; }
	    } else if (s.ttype == s.TT_EOF) curSy = ENDSY;
	    else curSy = EQSY;

	    if (DEBUG) {
		System.err.println("DEBUG> Scanner: '" + this + "'");
	    }
	} catch (IOException e) {
	    System.err.println("Scan error: " + e);  System.exit(0);
	}
    }

    public String toString () {
	return (curSy==NUMSY    ? "number "+curNum :
		curSy==VARSY    ? "variable "+curVar :
		curSy==EQSY     ? "symbol =" :
		curSy==ENDSY    ? "symbol end" :
		curSy==LOCKSY   ? "symbol lock" :
		curSy==PRINTSY  ? "symbol print" :
		curSy==UNLOCKSY ? "symbol unlock" : "**ERROR**");
    }
}


class ProgramQueue {
    private ArrayList q = new ArrayList();

    public void add (Statement st) {
	q.add(st);
    }

    public void addFirst (Statement st) {
	q.add(0, st);
    }

    public Statement get () {
	return (Statement)q.remove(0);
    }

    public boolean isEmpty () {
	return q.isEmpty();
    }
}


abstract class Statement {
    public Statement next = null;
    protected int id;

    public abstract Statement run (Main p, PrintStream print);
    public abstract int time ();

    protected final boolean DEBUG = false;
    protected void debug (String s) {
	if (DEBUG) 
	    System.err.println("DEBUG> process " + id + ": " + s);
    }
}

class AssignStm extends Statement {
    public static int execTime;
    private int varNum, value;

    public AssignStm (int n) { id = n; }

    public static Statement read (Scanner s, int id) {
	AssignStm st = new AssignStm(id);
	st.varNum = s.curVar.charAt(0) - 'a';  s.nextToken();  
	s.nextToken();  // Skip '='.
	st.value = s.curNum;  s.nextToken();  
	return st;
    }

    public Statement run (Main p, PrintStream print) {
	p.var[varNum] = value;  debug(""+(char)('a'+varNum)+" = "+value);  
	return next;
    }

    public int time () { return execTime; }
}

class EndStm extends Statement {
    public static int execTime;

    public EndStm (int n) { id = n; }

    public static Statement read (Scanner s, int id) {
	s.nextToken();  return new EndStm(id);
    }

    public Statement run (Main p, PrintStream print) {
	debug("end");  return null;
    }

    public int time () { return execTime; }
}

class LockStm extends Statement {
    public static int execTime;

    public LockStm (int n) { id = n; }

    public static Statement read (Scanner s, int id) {
	s.nextToken();  return new LockStm(id);
    }

    public Statement run (Main p, PrintStream print) {
	if (p.isBlocked) {
	    debug("lock (blocking process)");  
	    p.blocked.add(this);  return null;
	}
	debug("lock");  p.isBlocked = true;  return next;
    }

    public int time () { return execTime; }
}

class PrintStm extends Statement {
    public static int execTime;
    private int varNum;

    public PrintStm (int n) { id = n; }

    public static Statement read (Scanner s, int id) {
	PrintStm st = new PrintStm(id);  s.nextToken();  
	st.varNum = s.curVar.charAt(0) - 'a';  s.nextToken();  
	return st;
    }

    public Statement run (Main p, PrintStream print) {
	debug("print " + (char)('a'+varNum));
	print.println("" + id + ": " + p.var[varNum]);  return next;
    }

    public int time () { return execTime; }
}

class UnlockStm extends Statement {
    public static int execTime;

    public UnlockStm (int n) { id = n; }

    public static Statement read (Scanner s, int id) {
	s.nextToken();  return new UnlockStm(id);
    }

    public Statement run (Main p, PrintStream print) {
	if (p.blocked.isEmpty()) {
	    debug("unlock");  
	} else {
	    debug("unblock (unblocking process)");
	    p.ready.addFirst(p.blocked.get());
	}
	p.isBlocked = false;  return next;
    }

    public int time () { return execTime; }
}