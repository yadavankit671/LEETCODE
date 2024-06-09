import java.util.HashMap;

class Solution974 {
    public int subarraysDivByK(int[] nums, int k) {
        int count=0;
        int prefixsum=0;
        HashMap<Integer,Integer> mp= new HashMap<>();
        mp.put(0,1);
        for(int i=0;i<nums.length;i++){
            prefixsum=(prefixsum+nums[i]%k+k)%k;
            count+=mp.getOrDefault(prefixsum,0);
            mp.put(prefixsum,mp.getOrDefault(prefixsum, 0)+1);
        }
        return count;
    }
}

public class P974 {
    public static void main(String[] args) {
        // nums = [4,5,0,-2,-3,1], k = 5
        int[] nums={4,5,0,-2,-3,1};
        int k=5;
        Solution974 obj=new Solution974();
        System.out.println(obj.subarraysDivByK(nums, k));
    }
}
