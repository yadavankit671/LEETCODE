import java.util.*;;
class Solution {
    public int[] frequencySort(int[] nums) {
        int[][] arr = new int[201][2];
        for (int num : nums) {
            int idx = num <= 0 ? Math.abs(num) : 100 + num;
            arr[idx][0]++; 
            arr[idx][1] = num;
        }
        List<int[]> list = new ArrayList<>();
        for (int[] pair : arr) {
            if (pair[0] > 0) {
                list.add(pair);
            }
        }
        list.sort((a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(b[1], a[1]);
            }
            return Integer.compare(a[0], b[0]);
        });
        int index = 0;
        for (int[] pair : list) {
            for (int i = 0; i < pair[0]; i++) {
                nums[index++] = pair[1];
            }
        }
        return nums;
    }
}
public class P1636 {

}
