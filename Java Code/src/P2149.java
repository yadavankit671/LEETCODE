class Solution {
    public int[] rearrangeArray(int[] nums) {
        int size=nums.length;
        int[] result=new int[size];
        int positive=0;
        int negative=1;
        for(int i=0;i<size;i++){
            if(nums[i]>=0){
                result[positive]=nums[i];
                positive+=2;
            }
            else{
                result[negative]=nums[i];
                negative+=2;
            }
        }
        return result;
    }
    void print(int[]nums){
        if(nums.length==0){
            System.out.println("Nums is Empty !!");
            return;
        }
        System.out.print("Nums : "+nums[0]);
        for(int i=1;i<nums.length;i++){
            System.out.print(","+nums[i]);
        }
        System.out.println();
    }
    
}
/**
 * P2149
 */
public class P2149 {

    public static void main(String[] args) {
        Solution obj= new Solution();
        int[] nums={3,1,2,-5,-2,-4};
        obj.print(obj.rearrangeArray(nums));
    }
}
