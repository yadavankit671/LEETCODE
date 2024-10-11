class NumArray {
    private int[] prefixSum;
    private int[] buffer;
    public NumArray(int[] nums) {
        buffer = nums.clone();
        prefixSum = new int[nums.length];
        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.length; i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
    }
    
    public int sumRange(int left, int right) {
        return prefixSum[right] - prefixSum[left] + buffer[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
public class P303 {

}
