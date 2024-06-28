#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool isSafe(vector<vector<bool> > &board,int row,int col){
        // column check
        for(int i=0;i<row;i++){
            if(board[i][col]) return false;
        }
        // Diagonal Check: 
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]) return false;
        }
        for(int i=row,j=col;i>=0 && j<board.size();i--,j++){
            if(board[i][j]) return false;
        }
        return true;
    }
    void BackTrack(int row,int n,vector<vector<bool> > &board,int &result){
        if(row==n) {
            result++;
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(board,row,col)==false) continue;
            board[row][col]=true;
            BackTrack(row+1,n,board,result);
            board[row][col]=false;
        }
    }
    public :
    int totalQueens(int n){
        int result=0;
        vector<vector<bool> > board(n, vector<bool>(n,false));
        BackTrack(0,n,board,result);
        return result;
    }
};
int main(){

}