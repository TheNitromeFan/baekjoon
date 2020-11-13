/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg09307;

/**
 *
 * @author USER
 */
import java.util.Scanner;
import java.text.NumberFormat;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        NumberFormat fmt = NumberFormat.getCurrencyInstance();
        while (true) {
            double[] prices = new double[101];
            prices[1] = scanner.nextDouble();
            if(prices[1] < 0){
                break;
            }
    	    prices[2] = scanner.nextDouble();
   	    prices[3] = scanner.nextDouble();
            int n = scanner.nextInt();
            for(int i = 4; i <= n; ++i){
                prices[i] = Math.round(prices[i-3] * prices[i-2] / prices[i-1] * 100.0) / 100.0;
            }
            System.out.println("Month: " + n + " cost: " + fmt.format(prices[n]));
        }
    }  
}
