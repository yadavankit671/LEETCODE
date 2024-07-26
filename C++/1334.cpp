#include<bits/stdc++.h>
using namespace std;
class Solution{
    void floydWarshall(vector<vector<int>> &dist, int n){
        for (int k = 0; k < n; ++k){
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold){
        vector<vector<int>> dist(n, vector<int>(n, 10e4 + 1));
        for (const auto &edge : edges){
            int src = edge[0];
            int dst = edge[1];
            int wt = edge[2];
            dist[src][dst] = wt;
            dist[dst][src] = wt;
        }
        floydWarshall(dist, n);
        int result = -1;
        int minCity = INT_MAX;
        for (int i = 0; i < n; ++i){
            int count = 0;
            for (int j = 0; j < n; ++j){
                if (i != j && dist[i][j] <= distanceThreshold) count++;
            }
            if (count <= minCity){
                result = i;
                minCity = count;
            }
        }
        return result;
    }
};
int main(){
    vector<vector<int> > edges ={{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int n = 4;
    int distanceThreshold = 4;
    Solution obj;
    int res = obj.findTheCity(n, edges, distanceThreshold);
    cout<< res<< endl;
}
/*
edges[i] = [fromi, toi, weighti]
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
*/