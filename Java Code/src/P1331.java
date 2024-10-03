import java.util.*;

class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int[] result = new int[arr.length];
        int[] sortedArr = arr.clone();
        Arrays.sort(sortedArr);
        Map<Integer, Integer> mp = new HashMap<>();
        int rank = 1;
        for(int i = 0; i < arr.length; i++){
            if(!mp.containsKey(sortedArr[i])) mp.put(sortedArr[i], rank++);
        }
        for(int i = 0; i < arr.length; i++){
            result[i] = mp.get(arr[i]);
        }
        return result;
    }
}
public class P1331 {

}
