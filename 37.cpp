#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<char> > &board){
    if(board.empty()) return;
    cout<<"Board : "<<endl;
    for(auto arr : board){
        cout<<"{ "<<arr[0];
        for(int i=1;i<arr.size();i++){
            cout<<", "<<arr[i];
        }
        cout<<" }"<<endl;
    }
    
}
class Solution {
    private: 
    int getCoordinate(int i){
        if(i>=0 && i<3) return 0;
        if(i>=3 && i<6) return 3;
        return 6;
    }
    bool isValid(vector<vector<char> > &board, char num,int i,int j){
        for(int k=0;k<9;k++){
            if(board[i][k]==num) return false;
        }
        for(int k=0;k<9;k++){
            if(board[k][j]==num) return false;
        }
        int x=getCoordinate(i);
        int y=getCoordinate(j);
        for(int k=x;k<x+3;k++){
            for(int l=y;l<y+3;l++){
                if(board[k][l]==num) return false;
            }
        }
        return true;
    }
    bool BackTracking (vector<vector<char> > &board,int i,int j){
        if(i==9) return true;
        if(j==9) return BackTracking(board,i+1,0);
        if(board[i][j]!='.') return BackTracking(board,i,j+1);
        for(char k='1';k<='9';k++){
            if(isValid(board,k,i,j)){
                board[i][j]=k;
                if(BackTracking(board,i,j+1)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    public:
    void solveSudoku(vector<vector<char>>& board) {
        BackTracking(board,0,0);
    }
};
int main(){
    vector<vector<char> > board={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution obj;
    obj.solveSudoku(board);
    print(board);
}