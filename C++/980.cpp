#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void BackTracking(vector<vector<int> >&grid,int x,int y,int curr,int &totalSum,int &result){
        if(x<0 || y<0 || x>=grid.size() || y>=grid.at(0).size() || grid.at(x).at(y)==-1) return;
        if(grid.at(x).at(y)==2){
            if(curr==totalSum+1) result++;
            return;
        }
        grid.at(x).at(y)=-1;
        curr++;
        BackTracking(grid,x-1,y,curr,totalSum,result);
        BackTracking(grid,x+1,y,curr,totalSum,result);
        BackTracking(grid,x,y-1,curr,totalSum,result);
        BackTracking(grid,x,y+1,curr,totalSum,result);
        grid.at(x).at(y)=0;
    }
    pair<int,int> findStart(vector<vector<int> >&grid,int &totalSum){
        pair<int,int> start={-1,-1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.at(i).size();j++){
                if(grid.at(i).at(j)==0) totalSum++;
                else if(grid.at(i).at(j)==1){
                    start.first=i;
                    start.second=j;
                }
            }
        }
        return start;
    }
    public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int result=0;
        int totalSum=0;
        pair<int,int> start=findStart(grid,totalSum);
        BackTracking(grid,start.first,start.second,0,totalSum,result);
        return result;
    }
};
int main(){

}