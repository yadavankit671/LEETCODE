#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        int max=*max_element(nums.begin(),nums.end());
        int i=0;int j=0;
        while(j<nums.size()){
            if(nums[j]==max) mp[max]++;
            while(mp[max]>=k){
                ans+=n-j;
                if(nums[i]==max) mp[max]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
int main(){
    vector<int> nums={1,3,2,3,3};
    int k=2;
    Solution obj;
    cout<<obj.countSubarrays(nums,k);

}