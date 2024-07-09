import java.util.Arrays;

class Solution {
    private int maxima(int x,int y,int [][] mat){
        int result = 0;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                result=Math.max(result,mat[i][j]);
            }
        }
        return result;
    }
    public int[][] largestLocal(int[][] grid) {
        int[][] result=new int[grid.length-2][grid[0].length-2];
        for(int i=0;i<result.length;i++){
            for(int j=0;j<result[i].length;j++){
                result[i][j]=maxima(i,j,grid);
            }
        }
        return result;
    }
}
public class P2373 {
    public static void main(String[] args) {
        int[][] mat=new int[][]{{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
        Solution obj=new Solution();
        int[][] result=obj.largestLocal(mat);
        for(var x: result){
            System.out.println(Arrays.toString(x));
        }
    }
}
