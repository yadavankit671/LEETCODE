class Solution {
    private boolean isMagicSquare(int[][] grid,int row, int col){
        int[] freq = new int[10];
        for(int i = row; i < row + 3; i++){
            for(int j = col; j < col + 3; j++){
                int element = grid[i][j];
                if(element < 1 || element > 9 || freq[element] > 0) return false;
                freq[element]++;
            }
        }
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        for(int i = 0; i < 3; i++){
            int rowSum = 0;
            int colSum = 0;
            for(int j = 0; j < 3; j++){
                rowSum += grid[row + i][col + j];
                colSum += grid[row + j][col + i];
            }
            if(rowSum != sum || colSum != sum) return false;
        }
        int diagSum1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diagSum2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        return diagSum1 == sum && diagSum2 == sum;
    }
    public int numMagicSquaresInside(int[][] grid){
        int count = 0;
        int n = grid.length;
        int m = grid[0].length;
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < m - 2; j++){
                if(isMagicSquare(grid, i, j)) count++;
            }
        }
        return count;
    }
}
public class P840 {

}
