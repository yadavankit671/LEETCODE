#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int result = INT_MAX;
        vector<vector<int>> adjList(n);
        for (const auto &edge : edges){
            int u = edge[0], v = edge[1];
            adjList.at(u).push_back(v);
            adjList.at(v).push_back(u);
        }
        for (int node = 0; node < n; node++){
            vector<int> parent(n, -1);
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(node);
            dist[node] = 0;
            while (!q.empty()){
                int u = q.front();
                q.pop();
                for (int v : adjList[u]){
                    if (dist[v] == -1){
                        parent[v] = u;
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                    else if (parent[u] != v) result = min(result, dist[u] + dist[v] + 1);
                }
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
int main(){

}