import java.util.*;
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer,Integer> resMap = new HashMap<Integer,Integer>();
        Stack<Integer> st = new Stack<>();
        int index = nums2.length - 1;
        while(index>=0){
            while(!st.isEmpty() && st.peek()<=nums2[index]){
                st.pop();
            }
            resMap.put(nums2[index],st.isEmpty() ? -1 : st.peek());
            st.push(nums2[index]);
            index--;
        }
        for(int i = 0; i< nums1.length; i++){
            nums1[i]= resMap.getOrDefault(nums1[i], -1);
        }
        return nums1;
    }
}
public class P496{
    /*
    Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
    Output: [-1,3,-1]
     */
    public static void main(String[] args) {
        Solution obj = new Solution();
        int[] nums1 = {2,4};
        int[] nums2 = {1,2,3,4};
        int[] result = obj.nextGreaterElement(nums1, nums2);
        for(int x : result ) System.out.print(x+" ");
    }
}