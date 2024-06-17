import java.util.*;

class Solution3115 {
    private void SieveOfEratosthenes(boolean[] prime,int n){
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
    }
    public int maximumPrimeDifference(int[] nums) {
        int size=101;
        boolean[] prime =new boolean[size];
        Arrays.fill(prime,true);
        SieveOfEratosthenes(prime, size);
        prime[0]=false;
        prime[1]=false;
        int firstIndex=-1;
        int secondIndex=-1;
        for(int i=0;i<nums.length;i++){
            if(prime[nums[i]]){
                if(firstIndex==-1){
                    firstIndex=i;
                }
                else{
                    secondIndex=i;
                }
            }
        }
        if(firstIndex==-1 || secondIndex==-1) return 0;
        return secondIndex-firstIndex;
    }
}
public class P3115 {
    public static void main(String[] args) {
        Solution3115 obj = new Solution3115();
        int[] nums={4,2,9,5,3};
        System.out.println(obj.maximumPrimeDifference(nums));
    }
}
