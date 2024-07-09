class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int result=0;
        int size=customers.length;
        for(int i=0;i<size;i++){
            if(grumpy[i]==0){
                result+=customers[i];
            }
        }
        int grumpyMax=0;
        int temp=0;
        int left=0,right=0;
        while(right<size){
            if(grumpy[right]==1){
                temp+=customers[right];
            }
            if(right-left+1>minutes){// right-left+1 is window size
                if(grumpy[left]==1){
                    temp-=customers[left];
                }
                left++;
            }
            grumpyMax=Math.max(grumpyMax,temp);
        }
        return result+grumpyMax;
    }
}
public class P1052 {

}
