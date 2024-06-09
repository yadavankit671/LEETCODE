#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum=0;
        int count=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixSum=(prefixSum + nums[i]%k+k)%k; // instead of prefixSum this is prefixSum%k track
            // [5,1,3,4] k==6 , instead of 5,6,9,14.. 
            // here ==> 5,0,3,1 --> prefixSum %4 is being tracked ..
            // num[i]%k+k ensures that for negative number I have positive rem..
            // -2%6 == -2 | 4 so only taking positive counter part..
            count+=mp[prefixSum];
            mp[prefixSum]++;
        }
        return count;
    }
};
int main(){
    Solution s;
    vector<int> nums={4,5,0,-2,-3,1};
    int k=5;
    cout<<s.subarraysDivByK(nums,k)<<endl;
    return 0;
}