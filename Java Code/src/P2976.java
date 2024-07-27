import java.util.*;

class Solution {
    private final long INF = (long) 1e9;
    private int findGraphSize(char[] original, char[] changed) {
        Set<Character> st = new HashSet<>();
        int size = original.length;
        for(int i = 0; i < size; ++i){
            st.add(original[i]);
            st.add(changed[i]);
        }
        return st.size();
    }
    private void floydWarshall(long[][] graph){
        int n = graph.length;
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        int n = findGraphSize(original,changed);
        long[][] graph = new long[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(graph[i],INF);
            graph[i][i] = 0;
        }
        Map<Character, Integer> mp = new HashMap<>();
        int index = 0;
        for(int i = 0; i < cost.length; ++i){
            char org = original[i];
            char tar = changed[i];
            if(!mp.containsKey(org)) mp.put(org,  index++);
            if(!mp.containsKey(tar)) mp.put(tar,  index++);
            int u = mp.get(org);
            int v = mp.get(tar);
            graph[u][v] = Math.min(graph[u][v],cost[i]);
        }
        floydWarshall(graph);
        long totalCost = 0;
        for(int i = 0; i < source.length(); ++i){
            char src = source.charAt(i);
            char tar = target.charAt(i);
            if(!mp.containsKey(src) || !mp.containsKey(tar) || graph[mp.get(src)][mp.get(tar)] >= INF) return -1;
            totalCost += graph[mp.get(src)][mp.get(tar)];
        }
        return totalCost;
    }
}
public class P2976 {

}
