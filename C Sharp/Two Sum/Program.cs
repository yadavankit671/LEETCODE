using System.Globalization;

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        if(nums.Length==0) return new int[2];
        int len=nums.Length;
        int[] result=[0,0];
        for(int i=0;i<len;i++){
            if(nums.Contains(target-nums[i])){
                int temp=Array.IndexOf(nums,target-nums[i],i+1);
                if(temp!=i && temp!=-1){
                    result=[i,temp];
                    break;
                }
            }
        }
        return result;
    }
    public void print(int[] nums){
        if(nums.Length==0) return;
        foreach(var i in nums){
            Console.Write(i+" ");
        }
    }
}
class Program{
    public static void Main(string[] args){
        int[] nums=[3,2,4];
        int target=6;
        Solution s=new();
        s.print(s.TwoSum(nums,target));

    }
}