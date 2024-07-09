class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long sum=0,sacrifice=Integer.MAX_VALUE;
        int count=0;
        for(int elem: nums){
            if((elem^k)> elem){
                sum+=elem^k;
                count++;
                sacrifice=Math.min(sacrifice,(elem^k)-elem);
            }
            else{
                sum+=elem;
                sacrifice=Math.min(sacrifice,elem-(elem^k));
            }
        }
        if(count%2==0)
        return sum;
        return sum-sacrifice;
    }
}
//Input: nums = [1,2,1], k = 3, edges = [[0,1],[0,2]] ans==6
public class P3068 {
    public static void main(String[] args) {
        int[] nums=new int[]{24,78,1,97,44};
        int [][] edges=new int[][]{{0,1},{0,2}};
        int k=6;
        Solution obj=new Solution();
        System.out.println(obj.maximumValueSum(nums, k, edges));
    }
}
