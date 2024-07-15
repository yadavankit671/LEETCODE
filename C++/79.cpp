#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool BackTrack(vector<vector<char>> & board,string &word,int x,int y,int index,vector<vector<bool>> & visited){
        if(index == word.length()) return true;
        if(x<0 || y<0 || x>=board.size() || y>= board.at(0).size() || visited[x][y] || board[x][y]!=word.at(index)) return false;
        visited[x][y]=true;
        if( BackTrack(board,word,x-1,y,index+1,visited) ||
            BackTrack(board,word,x+1,y,index+1,visited) ||
            BackTrack(board,word,x,y-1,index+1,visited) ||
            BackTrack(board,word,x,y+1,index+1,visited)) return true;
        visited[x][y]=false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string &word) {
        ios_base::sync_with_stdio(false);
        vector<vector<bool> > visited(board.size(),vector<bool>(board.at(0).size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.at(0).size();j++){
                if(board[i][j]==word.at(0) && BackTrack(board,word,i,j,0,visited)) return true;
            }
        }
        return false;
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