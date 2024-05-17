#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool result = false;
    void solve(vector<vector<char>> & board,string word,int x,int y,int index,vector<vector<bool>> & buffer){
        if(result==true) return;
        if(index>=word.length()){
            result = true;  // This might be slow in leetcode but this is optimal and works 
            return;
        }
        if(x>=board.size() || y>=board.at(0).size()) return;
        if(word[index]==board.at(x).at(y)){
            buffer[x][y]=true;
            if(x>0&& ! buffer.at(x-1).at(y)) solve(board,word,x-1,y,index+1,buffer);
            if(x+1<board.size() && ! buffer.at(x+1).at(y)) solve(board,word,x+1,y,index+1,buffer); 
            if(y>0 && ! buffer.at(x).at(y-1)) solve(board,word,x,y-1,index+1,buffer);
            if(y+1<board.at(0).size() && ! buffer.at(x).at(y+1)) solve(board,word,x,y+1,index+1,buffer);
            if(index+1==word.length()) result=true;
            if(result==false) buffer[x][y]=false;
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        ios_base::sync_with_stdio(false);
        vector<vector<bool>> buffer(board.size(),vector<bool>(board.at(0).size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.at(0).size();j++){
                if(board[i][j]==word.at(0))
                    solve(board,word,i,j,0,buffer);
                if(result==true) return result;
            }
        }
        return result;
    }
};
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]] word="see"
int main(){
    vector<vector<char>> board={{'A','A','A','A'},
                                {'A','A','B','A'},
                                {'C','D','E','E'}};
    //vector<vector<char>> board={{'a'}};
    string word="AACDEBAAAE";
    Solution obj;
    cout<<obj.exist(board,word)<<endl;
}