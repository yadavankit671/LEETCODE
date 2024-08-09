#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int i = rStart, j = cStart;
        int diri = 0, dirj = 1;
        int twice = 2;
        vector<vector<int>> res;
        int moves = 1;
        int next_moves = 2;
        while (res.size() < rows * cols) {
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                res.push_back({i, j});
            }
            i += diri;
            j += dirj;
            moves -= 1;
            if (moves == 0) {
                int temp = diri;
                diri = dirj;
                dirj = -temp; 
                twice -= 1;
                if (twice == 0) {
                    twice = 2;
                    moves = next_moves;
                    next_moves += 1;
                } else {
                    moves = next_moves - 1;
                }
            }
        }
        return res;
    }
};
int main(){
    int rows = 5, cols = 6, rStart = 1, cStart = 4;
    Solution obj;
    vector<vector<int> > result = obj.spiralMatrixIII(rows, cols, rStart, cStart);
    for(auto x: result){
        for(auto y: x) cout<<y<<",";
        cout<<endl;
    }
}