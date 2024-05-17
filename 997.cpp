#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> buffer){
    if(buffer.empty()){
        cout<<"Buffer is empty "<<endl;
        return;
    }
    for(auto x: buffer){
        if(x.empty()) cout<<"empty ";
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<",";
        }
        cout<<endl;
    }
}
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> list(n+1,0);
        for(int i=0;i<trust.size();i++){
            list[trust.at(i).at(1)]++;
            list[trust.at(i).at(0)]--;
        }
        for(int i=0;i<list.size();i++){
            if(list[i]==n-1) return i;
        }
        return -1;
    }
};
//[[1,3],[1,4],[2,3],[2,4],[4,3]]
//{{1,3},{1,4},{2,3},{2,4},{4,3}}
int main(){
    vector<vector<int>> trust={{1,3},{1,4},{2,3},{2,4},{4,3}};
    int n=4;
    Solution obj;
    cout<<obj.findJudge(n,trust)<<endl;
}