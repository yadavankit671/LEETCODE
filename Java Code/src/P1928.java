import java.util.*;
class Solution {
    public int[] getConcatenation(int[] nums) {
        int[] result=new int[2*nums.length];
        for(int i=0;i<nums.length;i++){
            result[i]=nums[i];
            result[i+nums.length]=nums[i];
            // 1,2,3,1,2,3
        }
        return result;
    }
}
public class P1928{
    public static void main(String[] args) {
        Solution obj=new Solution();
        int [] nums={1,2,1};
        int [] result=obj.getConcatenation(nums);
        System.out.println(Arrays.toString(result));
    }
}