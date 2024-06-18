#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int> > buff;
        for(int i=0;i<profit.size();i++) buff.push_back({difficulty[i],profit[i]});
        sort(buff.begin(),buff.end());
        sort(worker.begin(),worker.end());
        int ans=0; int j=0;int best=0;
        for(int i=0;i<worker.size();i++){
            while(j<buff.size() && buff[j].first<=worker[i]) best=max(best,buff[j++].second);
            ans+=best;
        }
        return ans;
    }
};
int main(){

}