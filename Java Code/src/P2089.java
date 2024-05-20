import java.util.*;
class Solution2089 {
    public List<Integer> targetIndices(int[] nums, int target) {
        List<Integer> result = new ArrayList<Integer>();
        int small=0,count=0;
        for(int el: nums){
            if(el<target) small++;
            else if(el==target) count++;
        }
        while(count>0){
            result.add(small++);
            count--;
        }
        return result;
    }
}
public class P2089 {
    public static void main(String[] args) {
        int[] nums =new int[]{1,4,2,9,3,1,6,7,4,8,4,2};
        int target=4;
        Solution2089 obj=new Solution2089();
        List<Integer> result=obj.targetIndices(nums, target);
        System.out.println(Arrays.toString(result.toArray()));
    }
}
