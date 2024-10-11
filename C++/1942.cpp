#include<bits/stdc++.h>
using namespace std;
class Solution {
    private : 
    struct comp{
        bool operator() (pair<int,int> &a, pair<int,int> &b){
            return a.first > b.first;
        }
    };
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        pair<int,int> targetTime = {times[targetFriend][0],times[targetFriend][1]};
        sort(times.begin(),times.end(),[](vector<int> &a, vector<int> &b){ return a[0] < b[0];});
        priority_queue<pair<int,int>, vector<pair<int,int>> , comp> pq;
        set<int> avl;
        for(int i = 0; i < n; i++) avl.insert(i);
        for(int i = 0; i < n; i++){
            while(!pq.empty() && pq.top().first <= times[i][0]){
                avl.insert(pq.top().second);
                pq.pop();
            }
            int chair = *avl.begin();
            avl.erase(avl.begin());
            if(times[i][0] == targetTime.first && times[i][1] == targetTime.second) return chair;
            pq.push({times[i][1],chair});
        }
        return -1;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> times = {{3,10},{1,5},{2,6}};
    int targetFriend = 0;
    cout<<obj.smallestChair(times, targetFriend);
}