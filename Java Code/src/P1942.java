import java.util.*;
class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        int n = times.length;
        int[] target = times[targetFriend];
        Arrays.sort(times, (a,b)->a[0]-b[0]);
        Set<Integer> avl = new TreeSet<>();
        for(int i = 0; i < n; i++) avl.add(i);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[0]-b[0]);
        for(int i = 0; i < n; ++i){
            while(!pq.isEmpty() && pq.peek()[0] <= times[i][0]){
                avl.add(pq.poll()[1]);
            }
            int chair = avl.iterator().next();
            avl.remove(chair);
            if(times[i] == target) return chair;
            pq.add(new int[]{times[i][1],chair});
        }
        return -1;
    }
}
public class P1942 {

}
