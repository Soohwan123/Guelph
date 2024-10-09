import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        Set<String> deudboSet = new HashSet<String>();
        Set<String> bodoSet = new HashSet<String>();
        List<String> outputList = new ArrayList<>();

        //개행
        sc.nextLine();

        for(int i = 0; i<n; i++){
            deudboSet.add(sc.nextLine());
        }

        for(int i = 0; i<m; i++){
            bodoSet.add(sc.nextLine());
        }

        for(String a : deudboSet){
            if(bodoSet.contains(a)){
                outputList.add(a);
            }
        }

        Collections.sort(outputList);

        System.out.println(outputList.size());

        for (String string : outputList) {
            System.out.println(string);
        }

        
        sc.close();
    }
}