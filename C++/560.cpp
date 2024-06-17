#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum=0;
        int count=0;
        map<int,int> mp;
        mp[0]=1;
        for( int x : nums ){
            prefixSum+=x;
            if(mp.find(prefixSum-k)!=mp.end()){
                count+=mp[prefixSum-k];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};
int main(){
    Solution obj;
    vector<int> nums={-1,1,0}; // [1,-1],[0],[1,-1,0]
    cout<<obj.subarraySum(nums,0);
}