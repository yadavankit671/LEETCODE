class Solution {
    private boolean backTrack(char[][] board,String word,int x,int y,int index,boolean[][] visited){
        if(index==word.length()) return true;
        if(x<0 || y<0 || x>=board.length || y>=board[0].length || visited[x][y]) return false;
        if(board[x][y]!=word.charAt(index)) return false;
        visited[x][y] = true;
        if( backTrack(board, word, x-1, y, index+1,visited) ||
            backTrack(board, word, x+1, y, index+1,visited) ||
            backTrack(board, word, x, y-1, index+1,visited) ||
            backTrack(board, word, x, y+1, index+1,visited) ) return true;
        visited[x][y] = false;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        boolean[][] visited = new boolean[board.length][board[0].length];
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                if(board[i][j]==word.charAt(0) && backTrack(board, word,i,j,0,visited)) return true;
            }
        }
        return false;
    }
}
