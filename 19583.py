import sys


s, e, q = sys.stdin.readline().rstrip().split()
sh, sm = (int(x) for x in s.split(":"))
eh, em = (int(x) for x in e.split(":"))
qh, qm = (int(x) for x in q.split(":"))
start_time, end_time, quit_time = sh * 60 + sm, eh * 60 + em, qh * 60 + qm
entered, left = set(), set()
while True:
    try:
        line = sys.stdin.readline().rstrip()
    except EOFError:
        break
    if line == "":
        break
    t, name = line.split()
    th, tm = (int(x) for x in t.split(":"))
    time = th * 60 + tm
    if time <= start_time:
        entered.add(name)
    elif end_time <= time <= quit_time:
        left.add(name)
print(len(entered & left))
