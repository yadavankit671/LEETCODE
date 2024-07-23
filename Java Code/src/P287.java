class Solution {
    public int findDuplicate(int[] nums) {
        boolean[] array = new boolean[nums.length-1];
        for(int x : nums){
            if(array[x-1]==true) return x;
            else array[x-1] = true;
        }
        return -1;
    }
}
public class P287 {

}
