import java.util.*;

class Solution {
    public int findShortestCycle(int n, int[][] edges) {
        int result = Integer.MAX_VALUE;
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }
        for (int node = 0; node < n; node++) {
            int[] dist = new int[n];
            int[] parent = new int[n];
            Queue<Integer> q = new ArrayDeque<>();
            Arrays.fill(dist, -1);
            Arrays.fill(parent, -1);
            dist[node] = 0;
            q.offer(node);
            while (!q.isEmpty()) {
                int u = q.poll();
                for (int v : adjList.get(u)) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.offer(v);
                    } else if (parent[u] != v) {
                        result = Math.min(result, dist[u] + dist[v] + 1);
                    }
                }
            }
        }
        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
public class P2608 {
    public static void main(String[] args) {
        
    }
}
