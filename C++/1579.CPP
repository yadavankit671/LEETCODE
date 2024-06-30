#include<bits/stdc++.h>
using namespace std;
class DSU{
    private: 
    vector<int> parent;
    vector<int> rank;
    int components;
    public: 
    DSU(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
        rank.resize(n+1);
        components=n;
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent==y_parent){
            return;
        }
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[y_parent]>rank[x_parent]){
            parent[x_parent]=y_parent;
        }
        else {
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
        components--;
    }
    bool isSingle(){
        return components==1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);
        auto lambda=[](const auto &a, const auto &b){
            return a[0]>b[0];
        };
        sort(edges.begin(),edges.end(),lambda);
        int edgeCount=0;
        for(const auto &edge : edges){
            int type=edge[0];
            int u=edge[1];
            int v=edge[2];
            if(type==3){ // for Both 
                bool flag=false;  // if ege added or not
                // Alice
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u,v);
                    flag=true;
                }
                // Bob
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u,v);
                    flag==true;
                }
                if(flag) edgeCount++;
            }
            else if(type==2){ // BOB
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u,v);
                    edgeCount++;
                }
            }
            else { // ALICE
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u,v);
                    edgeCount++;
                }
            }
        }
        if(Alice.isSingle() && Bob.isSingle()) {
            return edges.size()-edgeCount;
        }
        return -1;
    }
};
int main(){

}