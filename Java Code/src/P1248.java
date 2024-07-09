import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int result = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        Map<Integer,Integer> mp= new HashMap<>();
        mp.put(0, 1);
        int right=0,sum=0;
        while(right<nums.length){
            sum+=nums[right];
            mp.put(sum,mp.getOrDefault(sum, 0)+1);
            if(sum>=k){
                result+=mp.get(sum-k);
            }
            right++;
        }
        return result;
    }
}
