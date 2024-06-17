#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
/*
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> rev;
        int j=0;
        for(int i=matrix.size()-1;i>=0;i--) {
            vector<int> temp;
            for(int k=matrix.size()-1;k>=0;k--) {
                temp.push_back(matrix[k][j]);
            }
            rev.push_back(temp);
            j++;
        }
        matrix=rev;
    }
    void print(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[i].size();j++) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};
int main(){
    vector<vector<int>> matrix;
    vector<int>v1={1,2,3};
    vector<int>v2={4,5,6};
    vector<int>v3={7,8,9};
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    Solution obj;
    obj.rotate(matrix);
    obj.print(matrix);
}