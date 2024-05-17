#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> result;
        vector<int> rowZeros;
        vector<int> columnZeros;
        vector<int> rowOnes;
        vector<int> columnOnes;
        int colSize=grid.at(0).size();
        int rowSize=grid.size();
        for(int i=0;i<rowSize;i++){
            int rowZero=0;
            int rowOne=0;
            for(int j=0;j<colSize;j++){
                if(grid[i][j]==0) rowZero++;
                else rowOne++;
            }
            rowZeros.push_back(rowZero);
            rowOnes.push_back(rowOne);
        }
        for(int i=0;i<colSize;i++){
            int colZero=0;
            int colOne=0;
            for(int j=0;j<rowSize;j++){
                if(grid[j][i]==0) colZero++;
                else colOne++;
            }
            columnZeros.push_back(colZero);
            columnOnes.push_back(colOne);
        }
        for(int i=0;i<rowSize;i++){
            vector<int> temp;
            for(int j=0;j<colSize;j++){
                temp.push_back(rowOnes[i]+columnOnes[j]-rowZeros[i]-columnZeros[j]);
            }
            result.push_back(temp);
        }
        return result;
    }
};
void print(vector<vector<int>> vec){
    if(vec.size()==0) {
        cout<<"Matrix is Empty !!!"<<endl;
        return;
    }
    cout<<"Matrix : [";
    for(int i=0;i<vec.size();i++){
        cout<<"["<<vec[i][0];
        for(int j=1;j<vec.at(i).size();j++){
            cout<<","<<vec[i][j];
        }
        cout<<"]";
    }
    cout<<"]\n";
}
int main(){
    vector<vector<int>> grid={{1,1,1},{1,1,1}};
    Solution obj;
    print(grid);
    vector<vector<int>> result=obj.onesMinusZeros(grid);
    cout<<"Resultant ";
    print(result);
}