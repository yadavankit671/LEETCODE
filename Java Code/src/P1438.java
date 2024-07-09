import java.util.LinkedList;

class Solution{
    public static int longestSubarray(int[] nums, int limit) {
        int result=0;
        int left=0;
        int right=0;
        int size= nums.length;
        LinkedList<Integer> minList= new LinkedList<>();
        LinkedList<Integer> maxList= new LinkedList<>(); 
        while(right<size){
            while(!maxList.isEmpty() && nums[right]>maxList.getLast()){
                maxList.removeLast();
            }
            maxList.addLast(nums[right]);
            while(!minList.isEmpty() && nums[right]<minList.getLast()){
                minList.removeLast();
            }
            minList.addLast(nums[right]);
            while(!maxList.isEmpty() && !minList.isEmpty() && maxList.getFirst()-minList.getFirst()>limit){
                if(nums[left]==maxList.getFirst()){
                    maxList.removeFirst();
                }
                if(nums[left]==minList.getFirst()){
                    minList.removeFirst();
                }
                left++;
            }
            result=Math.max(result,right-left+1);
            right++;
        }
        return result;
    }
}
