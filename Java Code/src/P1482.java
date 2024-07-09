import java.util.Arrays;
class Solution{
    private static int CountBouquet(int[] arr, int day,int k){
        int count=0, consecutive=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]<=day){
                consecutive++;
            }
            else consecutive=0;
            if(consecutive==k){
                count++;
                consecutive=0;
            }
        }
        return count;
    }
    public int minDays(int[]arr, int m, int k) {
        if(m*k>arr.length) return -1;
        int maxi=Arrays.stream(arr).max().getAsInt();
        int mini=1;
        int result=-1;
        while(mini<=maxi){
            int mid=mini+(maxi-mini)/2;
            int count=CountBouquet(arr, mid, k);
            if(count>=m){
                result=mid;
                maxi=mid-1;
            }
            else {
                mini=mid+1;
            }
        }
        return result;
    }
}
public class P1482 {
    public static void main(String[] args) {
        Solution obj= new Solution();
        int[] bloomDay= new int[]{};
        int m=2;
        int k=3;
        System.out.println(obj.minDays(bloomDay, m, k));
    }
}
