import java.util.Arrays;

public class P1509 {
    public int minDifference(int[] nums) {
        if(nums.length <=4) return 0;
        Arrays.sort(nums);
        int n=nums.length;
        int result=Math.min(nums[n-1]-nums[3],nums[n-2]-nums[2]);
        result=Math.min(result,nums[n-3]-nums[1]);
        result=Math.min(result,nums[n-4]-nums[0]);
        return result;
    }
}
