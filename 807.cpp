#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row(grid.size());
        vector<int> col(grid.size());
        int result=0;
        for(int i=0;i<grid.size();i++) {
            row[i]=INT_MIN;
            col[i]=INT_MIN;
            for(int j=0;j<grid.size();j++){
                row[i]=max(row[i],grid[i][j]);
                col[i]=max(col[i],grid[j][i]);
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.at(i).size();j++){
                int minimum=min<int>(row[i],col[j]);
                if(minimum>grid.at(i).at(j)) result+=(minimum-grid.at(i).at(j));
            }
        }
        return result;
    }
};
int main(){
    vector<vector<int>> grid={{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    Solution obj;
    cout<<obj.maxIncreaseKeepingSkyline(grid);
}