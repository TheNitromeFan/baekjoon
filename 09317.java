import java.util.*;
import java.text.*;
public class Main {
    public static void main(String[] args) {
        Scanner fin = new Scanner(System.in);
        NumberFormat fmt = NumberFormat.getInstance();
        fmt.setMinimumFractionDigits(2);
        fmt.setMaximumFractionDigits(2);
        while(true){
            double d = fin.nextDouble();
            int resw = fin.nextInt();
            int resh = fin.nextInt();
	  if (d == 0){
                break;
            }
	  double w = 16.0*d/Math.sqrt(337);
	  double h = 9.0*w/16.0;
	  System.out.println("Horizontal DPI: " + fmt.format(resw/w));
	  System.out.println("Vertical DPI: " + fmt.format(resh/h));
        }
    }
}
