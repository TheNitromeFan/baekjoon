import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(true) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            if (a == 0 && b == 0 && c == 0) {
                break;
            }
            int n1 = a;
            int n2 = b;
            for (int i = 0; i < c; i++) {
                int temp = n1;
                n1 = n2;
                n2 = n1 + temp;
            }
            System.out.println(n2);
        }
    }
}

