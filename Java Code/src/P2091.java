class Solution {
    public int minimumDeletions(int[] nums) {
        int result = 0;
        int min=Integer.MAX_VALUE;
        int minIndex=-1;
        int max=Integer.MIN_VALUE;
        int maxIndex=-1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]<min){
                min=nums[i];
                minIndex=i;
            }
            if(nums[i]>max){
                max=nums[i];
                maxIndex=i;
            }
        }
        result=Math.max(minIndex,maxIndex)+1;
        result=Math.min(result,nums.length-Math.min(minIndex,maxIndex));
        result=Math.min(result,Math.min(minIndex,maxIndex)+1+nums.length-Math.max(maxIndex,minIndex));
        return result;
    }
}
public class P2091 {

}
