import java.util.Arrays;

class Solution {
    public int[] shuffle(int[] nums, int n) {
        int [] result=new int[nums.length];
        for(int i=0,j=0;i<nums.length/2 && j<nums.length;i++){
            result[j++]=nums[i];
            result[j++]=nums[(nums.length/2)+i];
        }
        return result;
    }
}
public class P1470 {
    public static void main(String[] args) {
        Solution obj=new Solution();
        int [] nums=new int[]{2,5,1,3,4,7};
        int n=3;
        int[] result=obj.shuffle(nums, n);
        System.out.println(Arrays.toString(result));
    }
}
