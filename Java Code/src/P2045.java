import java.util.*;
class Solution {
    public int secondMinimum(int n, int[][] edges, int time, int change) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        for (int[] edge : edges) {
            int src = edge[0] - 1;
            int dst = edge[1] - 1;
            adjList.putIfAbsent(src, new ArrayList<>());
            adjList.putIfAbsent(dst, new ArrayList<>());
            adjList.get(src).add(dst);
            adjList.get(dst).add(src);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> a.getKey() - b.getKey());
        int[] min1 = new int[n];
        int[] min2 = new int[n];
        Arrays.fill(min1, Integer.MAX_VALUE);
        Arrays.fill(min2, Integer.MAX_VALUE);
        min1[0] = 0;
        pq.add(new AbstractMap.SimpleEntry<>(0, 0));
        while (!pq.isEmpty()) {
            Map.Entry<Integer, Integer> current = pq.poll();
            int timeElapsed = current.getKey();
            int node = current.getValue();
            if (min2[n - 1] != Integer.MAX_VALUE && node == n - 1) {
                return min2[n - 1];
            }
            int mult = timeElapsed / change;
            int adjustedTime = (mult % 2 == 1) ? change * (mult + 1) : timeElapsed;
            for (int neighbor : adjList.getOrDefault(node, Collections.emptyList())) {
                if (min1[neighbor] > adjustedTime + time) {
                    min2[neighbor] = min1[neighbor];
                    min1[neighbor] = adjustedTime + time;
                    pq.add(new AbstractMap.SimpleEntry<>(adjustedTime + time, neighbor));
                } else if (min2[neighbor] > adjustedTime + time && min1[neighbor] != adjustedTime + time) {
                    min2[neighbor] = adjustedTime + time;
                    pq.add(new AbstractMap.SimpleEntry<>(adjustedTime + time, neighbor));
                }
            }
        }
        return -1;
    }
}
public class P2045 {
    public static void main(String[] args) {
        Solution obj = new Solution();
        System.out.println(obj.hashCode());
    }
}
