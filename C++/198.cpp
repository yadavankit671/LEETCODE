#include<bits/stdc++.h>
using namespace std;
class Solution{
    private :
    //      notSkip,isSkip
    vector<pair<int,int>> dp;
    int solve(vector<int> &houses,int index, int n){
        if(index >= n) return 0;
        if(dp[index].second == -1) dp[index].second = solve(houses,index+1,n);
        if(dp[index].first == -1) dp[index].first = houses[index] + solve(houses,index+2,n);
        return max(dp[index].first,dp[index].second);
    }
    public : 
    int rob(vector<int> &houses){
        int n = houses.size();
        for(int i = 0; i < n; i++) dp.push_back({-1,-1});
        int result = solve(houses,0,n);
        return result;
    }
};

int main(){
    vector<int> houses = {1,2,3,1};
    Solution obj;
    cout<<obj.rob(houses)<<endl;
}