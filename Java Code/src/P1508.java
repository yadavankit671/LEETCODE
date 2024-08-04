import java.util.Arrays;
class Solution {
    private final int mod = (int) 1e9+7;
    public int rangeSum(int[] nums, int n, int left, int right) {
        int m = n * (n + 1) / 2;
        int[] arr = new int[m];
        int index = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                arr[index++] = sum;
            }
        }
        Arrays.sort(arr);
        int ans = 0;
        while(left <= right){
            ans = (ans + arr[left - 1]) % mod;
            left++;
        }
        return ans;
    }
}
public class P1508 {

}
