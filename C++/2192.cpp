#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int> > ans){
    for(auto &v:ans){
        if(v.empty()) {
            cout<<"[]"<<endl;
            continue;
        }
        cout<<"["<<v[0];
        for(int i=1;i<v.size();i++) cout<<","<<v[i];
        cout<<"]"<<endl;
    }
}
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n),adjList(n);
        for(const auto & edge : edges){
            adjList[edge[0]].push_back(edge[1]);
        }
        function<void(int,int)> dfs=[&](int child,int parent){
            for(int & x : adjList[child]){
                if(result.at(x).empty() || result.at(x).back()!=parent){
                    result.at(x).push_back(parent);
                    dfs(x,parent);
                }
            }
        };
        for(int i=0;i<n;i++) dfs(i,i);
        return result;
    }
};   
//[[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
//[[0,3],[5,0],[2,3],[4,3],[5,3],[1,3],[2,5],[0,1],[4,5],[4,2],[4,0],[2,1],[5,1]]

int main(){
    vector<vector<int> > edges={{0,3},{5,0},{2,3},{4,3},{5,3},{1,3},{2,5},{0,1},{4,5},{4,2},{4,0},{2,1},{5,1}};
    int n=6;
    Solution obj;
    print(obj.getAncestors(n,edges));
    
}
//[[2,4,5],[0,2,4,5],[4],[0,1,2,4,5],[],[2,4]]...