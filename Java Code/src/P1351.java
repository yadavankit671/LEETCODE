class Solution1351 {
    public int countNegatives(int[][] grid) {
        int result = 0;
        for( int [] arr : grid){
            int start=0;
            if(arr[start]<0) {
                result+=arr.length;
                continue;
            }
            int end=arr.length-1;
            if(arr[end]>=0) continue;
            while(start<end){
                int mid=(start+end)/2;
                if(arr[mid]<0) end=mid;
                else start=mid+1;
            }
            result+=arr.length-start;
        }
        return result;
    }
}
public class P1351 {
    public static void main(String[] args) {
        int[][] grid = new int[][]{{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
        Solution1351 obj = new Solution1351();
        System.out.println(obj.countNegatives(grid));
    }
}
