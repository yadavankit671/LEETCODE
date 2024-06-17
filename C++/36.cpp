#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int j=0,x=0,y=0;
        for(int i=0; i<9; i++){
            vector<char>temp;
            vector<char> temp2;
            vector<char> temp3;
            for(int k=0;k<9;k++){
                if(board[k][j]!='.'){
                    temp.push_back(board[k][j]);
                }
                if(board[i][k]!='.') temp2.push_back(board[i][k]);
            }
            //for 3x3 cube: 
            for(int z=x;z<x+3;z++){
                for(int k=y;k<y+3;k++){
                    if(board[z][k]!='.') temp3.push_back(board[z][k]);
                }
            }
            x+=3;
            if(x>8){
                x=0;
                y+=3;
            }
            set <char> vertical(temp.begin(),temp.end());
            set <char> horizontal(temp2.begin(),temp2.end());
            set <char> cube(temp3.begin(),temp3.end());
            if(vertical.size()<temp.size()|| horizontal.size()<temp2.size() || cube.size()<temp3.size()) return false;
            j++;
        }
        return true;
    }
    void print(vector<char> board){
        for(int i=0;i<board.size();i++){
            cout<<board[i]<<"  ";
        }
        cout<<"cube"<<endl;
    }
};
int main(){
    vector<vector<char>> board={
{'.','.','.','.','5','.','.','1','.'},
{'.','4','.','3','.','.','.','.','.'},
{'.','.','.','.','.','3','.','.','1'},
{'8','.','.','.','.','.','.','2','.'},
{'.','.','2','.','7','.','.','.','.'},
{'.','1','5','.','.','.','.','.','.'},
{'.','.','.','.','.','2','.','.','.'},
{'.','2','.','9','.','.','.','.','.'},
{'.','.','4','.','.','.','.','.','.'}};
    Solution s;
    if(s.isValidSudoku(board)) cout<<"Valid ";
    else cout<<"Invalid ";
}