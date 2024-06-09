class Solution53{
    public int maxSubArray(int[] nums){
        int result=Integer.MIN_VALUE;
        int currSum=0;
        for( int x : nums) {
            currSum+=x;
            result= currSum>result ? currSum: result;
            if (currSum<0) currSum=0;
        }
        return result;
    }
}
public class P53 {
    public static void main(String[] args) {
        Solution53 obj=new Solution53();
        int [] arr ={-2,1,-3,4,-1,2,1,-5,4};
        System.out.println(obj.maxSubArray(arr));
    }
}
