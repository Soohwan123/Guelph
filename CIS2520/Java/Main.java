import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt();
        int den1 = sc.nextInt();
        int num2 = sc.nextInt();
        int den2 = sc.nextInt();

        int new_den = LCM(den1, den2);
        //통분
        int a = ((new_den/den1)*num1);
        int b = ((new_den/den2)*num2);
        int new_num = a + b;

        int gcd = GCD(new_den, new_num);
        new_den /= gcd;
        new_num /= gcd;
        System.out.println(new_num + " " + new_den);

        sc.close();
    }

    private static int GCD(int a, int b){
        if(b == 0) return a;
        return GCD(b, a % b);
    }

    // 최소공배수 ( 유클리드 호제법 )
    private static int LCM(int a, int b){
        int gcd = GCD(a, b);
        return a * b / gcd;
    }

}

