public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        int len=nums.Length;
        if (nums==null || len==1) return false;
        int[] temp=new int[len];
        temp[0]=nums[0];
        for(int i=1;i<len;i++){
            if(temp.Contains(nums[i])) return true;
            temp.Append(nums[i]);
        }
        return false;
    }
}
public class Program{
    public static void Main(string[] args)
    {
        int[] arr=[1,2,3,4,1];
        Solution s=new();
        if(s.ContainsDuplicate(arr)) Console.WriteLine("Contains Duplicate !!");
        else Console.WriteLine("Does not contain duplicate");
    }
}