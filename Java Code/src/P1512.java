import java.util.Arrays;

class Solution1512 {
    public int numIdenticalPairs(int[] nums) {
        int result = 0;
        int[] buffer = new int[101];
        Arrays.fill(buffer, 0);
        for(int x: nums) buffer[x]++;
        for(int x: buffer) if(x>1) result+=x*(x-1)/2;
        return result;
    }
}
public class P1512 {
    public static void main(String[] args) {
        Solution1512 obj=new Solution1512 ();
        int[] nums={1,2,3,1,1,3};
        System.out.println(obj.numIdenticalPairs(nums));
    }
}
