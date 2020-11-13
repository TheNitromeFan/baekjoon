import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		long n = scanner.nextLong();
		while(n % 2 == 0){
			System.out.println(2);
			n /= 2;
		}
		for(long p = 3; p*p < n; p += 2){
			while(n % p == 0){
				System.out.println(p);
				n /= p;
			}
		}
		if(n > 1){
			System.out.println(n);
		}
	}
}