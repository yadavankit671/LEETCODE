#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int> > adjMat(n);
        for(const auto &edge : edges){
            int src = edge[0] - 1;
            int dst = edge[1] - 1;
            adjMat[src].push_back(dst);
            adjMat[dst].push_back(src);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<>> pq;
        vector<int> min1(n,INT_MAX);
        vector<int> min2(n,INT_MAX);
        pq.push({0,0});
        min1[0] = 0;
        while(!pq.empty()){
            auto [timeElapsed, node] = pq.top();
            pq.pop();
            if(min2[n-1] != INT_MAX && node == n-1) {
                return min2[n - 1];  // answer
            }
            int mult = timeElapsed/change;
            if(mult % 2 == 1){
                timeElapsed = change * (mult + 1);
            }
            for(auto & neighbour : adjMat[node]){
                if(min1[neighbour] > timeElapsed + time){
                    min2[neighbour] = min1[neighbour];
                    min1[neighbour] = timeElapsed + time;
                    pq.push({timeElapsed + time,neighbour});
                }
                else if(min2[neighbour] > timeElapsed + time && min1[neighbour] != timeElapsed + time){
                    min2[neighbour] = timeElapsed + time;
                    pq.push({timeElapsed + time,neighbour});
                }
            }
        }
        return -1;
    }
};
int main(){

}