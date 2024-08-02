class Solution{
    private int accumulate(int[] nums, int end){
        int sum = 0;
        for(int i = 0; i < end; i++) sum += nums[i];
        return sum;
    }
    public int minSwaps(int[] nums) {
        int size= nums.length;
        int oneCount = accumulate(nums,size);
        int sum = accumulate(nums, oneCount);
        int maxOnes = sum;
        int start = 0;
        int end = oneCount;
        while(end < 2 * size){
            sum -= nums[start % size];
            sum += nums[end % size];
            maxOnes = Math.max(maxOnes, sum);
            start++;
            end++;
        }
        return oneCount - maxOnes;
    }
}

public class P2134 {

}