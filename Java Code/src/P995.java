import java.util.*;

public class P995 {
    public static int minKBitFlips(int[] nums, int k) {
        int size=nums.length;
        int result=0;
        Deque<Integer> flips= new ArrayDeque<Integer>();
        int index=0;
        while(index<size){
            if(!flips.isEmpty() && index>=flips.peek()){
                flips.poll();
            }
            if((nums[index] + flips.size())%2==0){
                if(index+k>size) return -1;
                result++;
                flips.offer(index+k);
            }
            index++;
        }
        return result;
    }
    public static void main(String[] args) {
        int[] nums={0,0,0,1,0,1,1,0};
        int k=3;
        System.out.println(minKBitFlips(nums, k));
    }
}

/*

 */