import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException{
        String[] players = {"mumu", "soe", "poe", "kai", "mine"};
        String[] callings = {"kai", "kai", "mine", "mine"};
                
        //탐색 시간복잡도 줄이기 위해 HashMap 사용
        HashMap<String, Integer> players_map = new HashMap<>();
        for(int i = 0; i < players.length; i++){
            players_map.put(players[i], i);
        }
        
        for(int i = 0; i < callings.length; i++){
            int idx = players_map.get(callings[i]);
            
            if(idx != 0){
                String temp = players[idx-1];
                players[idx-1] = players[idx];
                players[idx] = temp;
            }
        }
       
        for (String string : players) {
            System.out.print(string + " ");
        }
    }
}

