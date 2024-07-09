import java.util.Arrays;
import java.util.Comparator;

class Solution {
    private boolean allZeros(int[] nums){
        for(int x : nums) if(x!=0) return false;
        return true;
    }
    public String largestNumber(int[] nums) {
        if(allZeros(nums)) return "0";
        StringBuilder result=new StringBuilder();
        String[] buff=new String[nums.length];
        for(int i=0;i<nums.length;i++) buff[i]=String.valueOf(nums[i]);
        Comparator <String> cmp = (a,b)->{
            String s1=a+b;
            String s2=b+a;
            return s2.compareTo(s1);
        };
        Arrays.sort(buff,cmp);
        for(String str: buff) result.append(str);
        return result.toString();
    }
}
public class P179 {
    public static void main(String[] args) {
        int[] nums={74,21,33,51,77,51,90,60,5,56};
        Solution obj=new Solution();
        System.out.println("\""+obj.largestNumber(nums)+"\"");
    }
}