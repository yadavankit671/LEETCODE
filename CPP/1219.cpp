#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    int result=0;
    void solve(vector<vector<int> > & grid,int x,int y,int curr_sum){
        if(x<0 || y<0 || x>=grid.size() || y>=grid.at(0).size() || grid[x][y]==0){
            return;
        }
        int curr=grid[x][y];
        curr_sum+=curr;
        grid[x][y]=0;
        result=max(result,curr_sum);
        solve(grid,x+1,y,curr_sum);
        solve(grid,x-1,y,curr_sum);
        solve(grid,x,y+1,curr_sum);
        solve(grid,x,y-1,curr_sum);
        grid[x][y]=curr;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid.at(i).size();j++)
                if(grid[i][j])
                    solve(grid,i,j,0);
        return result;
    }
};
int main(){
    vector<vector<int> > grid={{1,6,1},{5,8,7},{1,9,1}};
    Solution obj;
    cout<<obj.getMaximumGold(grid);
}