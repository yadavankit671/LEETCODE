#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int> > & vec){
    if(vec.empty()) return;
    cout<<"Matrix :\n[";
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
    void solveRow(vector<vector<int> > &grid,int row){
        for(int i=0;i<grid.at(row).size();i++)
            grid[row][i]=(grid[row][i]==0)?1:0;
    }
    void solveCol(vector<vector<int> > &grid,int col){
        for(int i=0;i<grid.size();i++)
            grid[i][col]=(grid[i][col]==1)?0:1;
        
    }
    int binaryToInt(vector<int> &arr){
        int i=arr.size()-1;
        int result=0;
        int power=0;
        for(;i>=0;i--){
            if(arr[i]==1)
            result+=pow(2,power);
            power++;
        }
        return result;
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cout<<"Before ";
        print(grid);
        // solve row
        for(int i=0;i<grid.size();i++){
            if(grid.at(i).at(0)==0) solveRow(grid,i);
        }
        //solve column
        for(int i=1;i<grid.at(0).size();i++){
            int zero_count=0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==0) zero_count++;
            }
            if(zero_count>grid.size()-zero_count) solveCol(grid,i);
        }
        cout<<"After ";
        print(grid);
        int sum=0;
        for(auto x: grid) sum+=binaryToInt(x);
        return sum;
    }
};
int main(){
    vector<vector<int> > grid={{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    Solution obj;
    cout<<obj.matrixScore(grid);
}