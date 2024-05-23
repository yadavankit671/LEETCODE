import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution2597 {
    private int result=0;
    private boolean isPresent(List<Integer> curr,int element) {
        int i=0;
    int j=curr.size()-1;
    while(i<=j) { 
        int mid=i+(j-i)/2; 
        if (curr.get(mid)==element) return true;
        else if (curr.get(mid)>element) j=mid-1;
        else i=mid+1;
    }
    return false; 
    }
    private void backTracking(int[] nums,int k,int index,List<Integer> curr){
        if(index==nums.length) return;
        if(curr.isEmpty() || isPresent(curr, nums[index])==false){
            curr.add(nums[index]+k);
            backTracking(nums, k, index+1, curr);
            result++;
            // for print: // note that each element in curr will be nums[index]+k
            //System.out.println(curr.toString());
            curr.removeLast();
        }
        backTracking(nums, k, index+1, curr);
    }
    public int beautifulSubsets(int[] nums, int k) {
        Arrays.sort(nums);
        List<Integer> curr =new ArrayList<>();
        backTracking(nums, k, 0, curr);
        return result;
    }
}
public class P2597 {
    public static void main(String[] args) {
        int[] nums={4,2,5,9,10,3};
        int k=2;
        Solution2597 obj= new Solution2597();
        System.out.println("Result : "+ obj.beautifulSubsets(nums, k));
    }
}
