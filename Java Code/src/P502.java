import java.util.*;

class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = capital.length;
        List<Integer> indexes = new ArrayList<>();
        for(int i=0;i<n;i++) indexes.add(i);
        indexes.sort((a,b)->{
            int dif = capital[a] - capital[b];
            return dif == 0? profits[a] - profits[b] : dif;
        });
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int currIndex = 0;
        for (int i = 0; i < k; i++) {
            while (currIndex < n && capital[indexes.get(currIndex)] <= w) {
                pq.add(-profits[indexes.get(currIndex)]);
                currIndex++;
            }
            if (!pq.isEmpty()) {
                w -= pq.poll();
            } else {
                break; 
            }
        }
        return w;
    }
}

public class P502 {

}
