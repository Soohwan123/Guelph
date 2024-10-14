import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        for(int i = n; i <= m; i++){
            int j = 3;
            boolean is_prime = true;

            //소수찾기
            while(true){
                if(i < 2){
                    is_prime = false;
                }
                else if(i == 2){
                    is_prime = true;
                }
                else if(i % 2 == 0){
                    is_prime = false;
                }
                else{
                    while(j <= Math.sqrt(i)){
                        if(i % j == 0){
                            is_prime = false;
                            break;
                        }
                        j += 2;
                    }
                }
    
                if(is_prime){
                    System.out.println(i);
                    j = 3;
                    break;
                } else {
                    is_prime = true;
                    j = 3;
                    break;
                }
            }
        }

        sc.close();
    }
}

