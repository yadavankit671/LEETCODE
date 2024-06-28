#include<bits/stdc++.h>
using namespace std;
class Solution {
    private : 
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
    void makeResult(vector<vector<bool> > &board,vector<vector<string> > &result){
        vector<string> temp;
        for(vector<bool> row : board){
            string str="";
            for(bool b : row){
                if(b) str+="Q";
                else str+=".";
            }
            temp.push_back(str);
        }
        result.push_back(temp);
    }
    void BackTrack(int row,int n,vector<vector<bool> > &board,vector<vector<string> > &result){
        if(row==n){
            makeResult(board,result);
            return;
        }
        for(int col=0;col<n;col++){
            if(!isSafe(board,row,col)) continue;
            board[row][col]=true;
            BackTrack(row+1,n,board,result);
            board[row][col]=false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<string> > result;
        vector<vector<bool>> board(n, vector<bool>(n,false));
        BackTrack(0,n,board,result);
        return result;
    }
};
int main(){

}