#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool isMinimum(vector<vector<int> >& matrix,int column, int element){
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][column]>element) return false;
        }
        return true;
    }
    public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> result;
        for(int i=0;i<matrix.size();i++){
            pair<int,int> min(INT_MAX,-1);
            for(int j=0;j<matrix.at(i).size();j++){
                if(matrix[i][j]<min.first){
                    min={matrix[i][j],j};
                }
            }
            if(isMinimum(matrix,min.second,min.first)) result.push_back(min.first);
        }
        return result;
    }
};
int main(){

}