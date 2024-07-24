import java.util.*;

class Solution {
    private int getVal(int[] mapping, int val) {
        int res = 0;
        String value = Integer.toString(val);
        for (int i = 0; i < value.length(); ++i) {
            res = res * 10 + mapping[value.charAt(i) - '0'];
        }
        return res;
    }

    public int[] sortJumbled(int[] mapping, int[] nums) {
        List<int[]> map = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            map.add(new int[]{nums[i], getVal(mapping, nums[i])});
        }
        map.sort((a, b) -> Integer.compare(a[1], b[1]));
        for (int i = 0; i < nums.length; ++i) {
            nums[i] = map.get(i)[0];
        }
        return nums;
    }
}

public class P2191 {

}
