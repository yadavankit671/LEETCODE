import java.util.List;
import java.util.ArrayList;
class Solution {
    private void BackTracking(List<List<Integer>> result,int[] nums,List<Integer> curr,int index){
        result.add(new ArrayList<>(curr));
        for(int i=index;i<nums.length;i++){
            curr.add(nums[i]);
            BackTracking(result,nums,curr,i+1);
            curr.removeLast();
        }
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> curr=new ArrayList<>();
        BackTracking(result,nums,curr,0);
        return result;
    }
}
public class P78 {
    public static void main(String[] args) {
        int[] nums=new int[]{1,2,3};
        Solution obj=new Solution();
        List<List<Integer>> result=obj.subsets(nums);
        for(List<Integer> arr : result){
            System.out.println(arr.toString());
        }
    }
}
