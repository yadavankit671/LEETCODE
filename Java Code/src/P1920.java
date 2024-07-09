import java.util.*;
class Solution {
    public int[] buildArray(int[] nums) {
        int [] result = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            result[i]=nums[nums[i]];
        }
        return result;
    }
}
public class P1920 {
    public static void main(String[] args) {
        Solution obj=new Solution();
        int[] nums=new int[]{0,2,1,5,3,4};
        System.out.println(Arrays.toString(obj.buildArray(nums)));
    }
}
