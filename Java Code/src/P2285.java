// import java.util.*;

import java.util.*;

public class P2285 {
    public long maximumImportance(int n, int[][] roads) {
        // GoTo 2285.cpp in C++ for BruteForce approach for better understading
        long result = 0;
        int[] buffer= new int[n];
        for(int[] road: roads){
            int u=road[0];
            int v=road[1];
            buffer[u]++;
            buffer[v]++;
        }
        Arrays.sort(buffer);
        for(int i=0;i<buffer.length;i++){
            result+=(long)buffer[i]*(i+1);
        }
        return result;
    }
    public static void main(String[] args) {
        P2285 obj = new P2285();
        int[][] roads ={{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
        int n=5;
        System.out.println(obj.maximumImportance(n, roads));
    }
}
