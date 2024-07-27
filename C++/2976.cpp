#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    const int size = 26;
    const long INF = 1e9;
    void floydWarshall(vector<vector<long> >& dist){
        for(int k = 0; k < size; ++k){
            for(int i = 0; i < size; ++i){
                for(int j = 0; j < size; ++j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<long> > graph(size,vector<long>(size,INF)); 
        for(int i = 0; i < size; i++) graph[i][i] = 0;
        for(int i = 0; i < cost.size(); ++i){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            graph[u][v] = min<long>(graph[u][v], cost[i]);
        }
        floydWarshall(graph);
        long long totalCost = 0;
        for(int i = 0; i < source.length(); ++i){
            int src = source[i] - 'a';
            int tar = target[i] - 'a';
            if(graph[src][tar] >= INF) return -1;
            totalCost += graph[src][tar];
        }
        return totalCost;
    }
};
int main(){
    
}