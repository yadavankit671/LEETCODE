import java.util.*;
class Solution{
    public boolean checkSubarraySum(int[] nums, int k) {
        int prefixSum=0;
        HashMap<Integer,Integer> mp= new HashMap<>();
        mp.put(0, -1);
        for(int i=0;i<nums.length;i++){
            prefixSum+=nums[i];
            int rem=(k==0)? prefixSum: prefixSum%k;
            if(mp.containsKey(rem)){
                if(i-mp.get(rem)>1) return true;
            }
            else mp.put(rem, i);
        }
        return false;
    }
}
public class P523 {
    public static void main(String[] args) {
        int[] arr = {5,0,0,0};
        int k=6;
        Solution obj= new Solution();
        System.out.println(obj.checkSubarraySum(arr, k));
    }
}
