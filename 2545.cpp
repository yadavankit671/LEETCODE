#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> result){
    if(result.empty()){
        cout<<"Empty List !!"<<endl;
        return;
    }
    cout<<"Result :"<<endl;
    for(auto x:result){
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<",";
        }
        cout<<endl;
    }
}
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(),score.end(),[k](vector<int>&a,vector<int>&b){return a[k]>b[k];});
        return score;
    }
};
int main(){
    vector<vector<int>> score={{10,6,9,1},{7,5,11,2},{4,8,3,15}};
    int k=2;
    Solution obj;
    print(obj.sortTheStudents(score,k));
}