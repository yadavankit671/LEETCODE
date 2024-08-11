class Solution {
    private int max_element(int[] nums){
        int max = 0;
        for(int i = 0; i < nums.length; i++){
            max = Math.max(max, nums[i]);
        }
        return max;
    }
    private int solve(int start,int end,int[] houses){
        int[] dp = new int[end - start];
        dp[0] = houses[start];
        dp[1] = Math.max(houses[start],houses[start + 1]);
        for(int i = start + 2; i < end; i++){
            dp[i - start] = Math.max(dp[i - start -1], houses[i] + dp[i - start -2]);  // i - start is used to get the index when excluding the start
        }
        return dp[dp.length - 1];
    }
    public int rob(int[] nums){
        if(nums.length < 4) return max_element(nums);
        int n = nums.length;
        return Math.max(solve(0,n-1,nums),solve(1,n,nums));
    }
}
public class P213 {

}
