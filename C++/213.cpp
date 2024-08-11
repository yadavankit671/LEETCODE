#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int start, int end, vector<int> &houses){
        vector<int> dp(end - start, 0);
        dp[0] = houses[start];
        dp[1] = max(houses[start],houses[start + 1]);
        for(int i = start + 2; i < end; i++){
            dp[i - start] = max(dp[i - start -1], houses[i] + dp[i - start -2]);  // i - start is used to get the index when excluding the start
        }
        return dp[dp.size() - 1];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 4) return *max_element(nums.begin(),nums.end());
        int n = nums.size();
        return max(solve(0,n-1,nums),solve(1,n,nums));
    }
};
int main(){
    vector<int> nums = {1,2,3};
    Solution obj;
    cout<<obj.rob(nums);
}