import java.util.*;
class Solution {
    private boolean isMinimum(int[][] matrix, int col,int min_element){
        for(int i=0;i<matrix.length;i++){
            if(matrix[i][col]<min_element) return false;
        }
        return true;
    }
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        for(int i=0;i<matrix.length;i++){
            int min_element = Integer.MAX_VALUE;
            int column = -1;
            for(int j=0;j<matrix[i].length;j++){
                if(matrix[i][j]<min_element){
                    min_element = matrix[i][j];
                    column = j;
                }
            }
            if(isMinimum(matrix, column, min_element)) result.add(min_element);
        }
        return result;
    }
}
public class P1380 {

}
