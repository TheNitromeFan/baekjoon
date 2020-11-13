/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg04379;

/**
 *
 * @author USER
 */
import java.util.*;
import java.math.BigInteger;

public class Main {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t, a, b;
    
        StringBuilder x = new StringBuilder("1");
        for(int i = 0; i < 99; ++i){
            x.append("0");
        }
        
        BigInteger threshold = new BigInteger(x.toString());
        
        try{
            while(true){
                t = scanner.nextInt();
                a = scanner.nextInt();
                b = scanner.nextInt();
                if(t == 1 || a % b > 0){
                    System.out.println(String.format("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits.", t, a, t, b));
                    continue;
                }
                BigInteger T = BigInteger.valueOf(t);
                BigInteger TB = BigInteger.ONE;
                for(int i = 0; i < b; ++i){
                    TB = TB.multiply(T);
                    if(TB.compareTo(threshold) >= 0){
                        break;
                    }
                }
                BigInteger NTB = BigInteger.ONE;
                BigInteger S = BigInteger.ZERO;
                for(int i = 0; i < a; i += b){
                    S = S.add(NTB);
                    if(S.compareTo(threshold) >= 0){
                        break;
                    }
                    NTB = NTB.multiply(TB);
                }
                if(S.compareTo(threshold) >= 0){
                    System.out.println(String.format("(%d^%d-1)/(%d^%d-1) is not an integer with less than 100 digits.", t, a, t, b));
                }else{
                    System.out.println(String.format("(%d^%d-1)/(%d^%d-1) %s", t, a, t, b, S.toString()));
                }
            }
        }catch(Exception e){
        }
    }
    
}
