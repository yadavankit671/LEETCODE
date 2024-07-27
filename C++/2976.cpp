#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    const long INF = 1e9;
    void floydWarshall(vector<vector<long> >& dist,int n){
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int findGraphSize(vector<char>& original,vector<char>& changed){
        set<char> st(original.begin(),original.end());
        st.insert(changed.begin(),changed.end());
        return st.size();
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = findGraphSize(original,changed); // find the size of the graph // only required characters
        vector<vector<long> > graph(n,vector<long>(n,INF)); 
        for(int i = 0; i < n; i++) graph[i][i] = 0;
        unordered_map<char,int> mp;
        int index = 0;
        for(int i = 0; i < cost.size(); ++i){
            char org = original[i];
            char tar = changed[i];
            if(mp.find(org) == mp.end()) mp[org] = index++;
            if(mp.find(tar) == mp.end()) mp[tar] = index++;
            int u = mp[org];
            int v = mp[tar];
            graph[u][v] = min<long>(graph[u][v], cost[i]);
        }
        floydWarshall(graph,n);
        long long totalCost = 0;
        for(int i = 0; i < source.length(); ++i){
            char src = source[i];
            char tar = target[i];
            if(mp.find(src) == mp.end() || mp.find(tar) == mp.end() || graph[mp[src]][mp[tar]] >= INF) return -1;
            totalCost += graph[mp[src]][mp[tar]];
        }
        return totalCost;
    }
};
int main(){
    
}