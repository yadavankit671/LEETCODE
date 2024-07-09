class Solution {
    private int result=0;
    private boolean isSafe(int row,int col,boolean[][] board){
        // column check
        for(int i=0;i<row;i++){
            if(board[i][col]) return false;
        }
        // Diagonal Check: 
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]) return false;
        }
        for(int i=row,j=col;i>=0 && j<board.length;i--,j++){
            if(board[i][j]) return false;
        }
        return true;
    }
    private void BackTrack(int row,int n,boolean[][] board){
        if(row==n){
            result++;
            return;
        }
        for(int col=0;col<n;col++){
            if(!isSafe(row,col,board)) continue;
            board[row][col]=true;
            BackTrack(row+1, n, board);
            board[row][col]=false;
        }
    }
    public int totalNQueens(int n) {
        boolean[][] board= new boolean[n][n];
        BackTrack(0, n, board);
        return result;
    }
}
