#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int size=mat.size();
        if(size==1) return mat.at(0).at(0);
        int result=0;
        for(int i=0; i<size/2; i++){
            result+=mat.at(i).at(i);
            result+=mat.at(i).at(size-1-i);
            result+=mat.at(size-1-i).at(i);
            result+=mat.at(size-1-i).at(size-1-i);
        }
        if(size%2!=0) result+=mat.at(size/2).at(size/2);
        return result;
    }
};
int main(){
    vector<vector<int>> mat={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    Solution obj;
    cout<<obj.diagonalSum(mat);
}