import java.util.ArrayList;
import java.util.List;
class Solution {
    private boolean isSafe(int[][] board,int row,int col){
        // column check
        for(int i=0;i<row;i++){
            if(board[i][col]==1) return false;
        }
        // Diagonal Check: 
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]==1) return false;
        }
        for(int i=row,j=col;i>=0 && j<board.length;i--,j++){
            if(board[i][j]==1) return false;
        }
        return true;
    }
    private void makeResult(int[][]board,List<List<String>> result){
        List<String> temp = new ArrayList<>();
        for(int[] array : board){
            StringBuilder str= new StringBuilder();
            for(int val : array) 
                str.append(val==1 ? "Q" : ".");
            temp.add(str.toString());
        }
        result.add(temp);
    }
    private void BackTrack(int row, int n, int[][] board, List<List<String> > result ){
        if(row==n){
            makeResult(board,result);
            return;
        }
        for(int col=0;col<n;col++){
            if(!isSafe(board,row,col)) continue;
            board[row][col]=1;
            BackTrack(row+1,n,board,result);
            board[row][col]=0;
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String> > result = new ArrayList<>();
        int[][] board= new int[n][n];
        BackTrack(0, n, board, result);
        return result;
    }
}
public class P51{
    public static void main(String[] args) {
        Solution obj = new Solution();
        int n=4;
        List<List<String>> result = obj.solveNQueens(n);
        for( List<String> lst : result){
            for(int i=0;i<lst.size();i++){
                System.out.println("["+lst.get(i)+"]");
            }
            System.out.println("\n");
        }
    }
}
