import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int num = sc.nextInt();
        int generator = 0;
        int sum = 0;
        List<Integer> sumList = new ArrayList<>();

        String numStr;
        int length = Integer.toString(num).length();

        for(int i=9*length;i>=length*1;i--){
            sum = 0;
            generator = num - i;
            if(generator > 0){
                numStr = Integer.toString(generator);

                // 각 자리수를 더함
                for (int j = 0; j < numStr.length(); j++) {
                    sum += Character.getNumericValue(numStr.charAt(j));
                }
    
                if(generator+sum == num){
                    sumList.add(generator);
                }
            } 
        }

        Collections.sort(sumList);

        if (!sumList.isEmpty()) {
            System.out.println(sumList.get(0));
        } else{
            System.out.println(0);
        }

        sc.close();
    }
}