import java.util.*;

class Solution {
    private final int size = 26;
    private final long INF = (long) 1e9;
    private void floydWarshall(long[][] graph){
        for(int k = 0; k < size; ++k){
            for(int i = 0; i < size; ++i){
                for(int j = 0; j < size; ++j){
                    graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        long[][] graph = new long[size][size];
        for (int i = 0; i < size; i++) {
            Arrays.fill(graph[i],INF);
            graph[i][i] = 0;
        }
        for(int i = 0; i < cost.length; ++i){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            graph[u][v] = Math.min(graph[u][v],cost[i]);
        }
        floydWarshall(graph);
        long totalCost = 0;
        for(int i = 0; i < source.length(); ++i){
            int u = source.charAt(i) - 'a';
            int v = target.charAt(i) - 'a';
            if(graph[u][v] >= INF) return -1;
            totalCost += graph[u][v];
        }
        return totalCost;
    }
}
public class P2976 {

}
