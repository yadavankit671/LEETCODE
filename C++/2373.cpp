#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int> > & vec){
    if(vec.empty()) return;
    cout<<"Vector :\n[";
    for(int i=0;i<vec.size();i++){
        cout<<'['<<vec[i][0];
        for(int j=1;j<vec.at(i).size();j++){
            cout<<","<<vec[i][j];
        }
        if(i<vec.size()-1)
        cout<<"]\n";
        else cout<<']';
    }
    cout<<"]\n\n";
}
class Solution {
    private: 
    int solve(vector<vector<int> > grid,int x,int y){        
        int res=INT_MIN;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                res=max(res,grid[i][j]);
            }
        }
        return res;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        vector<vector<int> > result(grid.size()-2,vector<int>(grid.at(0).size()-2,0));
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result.at(i).size();j++){
                result[i][j]=solve(grid,i,j);
            }
        }
        return result;
    }
};
int main(){
    vector<vector<int> > grid={{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    print(grid);
    Solution obj;
    vector<vector<int> > result=obj.largestLocal(grid);
    print(result);

}