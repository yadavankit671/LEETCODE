#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int> nums,int k){
        vector<int> freq(nums.size()+1,0);
        int i=0, j=0;
        int ans=0;
        int n=nums.size();
        int dist=0;
        while(j<n){
            freq[nums[j]]++;
            if(freq[nums[j]]==1) dist++;
            while(dist>k){
                freq[nums[i]]--;
                if(freq[nums[i]]==0) dist--;
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans=0;
        if(k==1) ans=solve(nums,k);
        // sub array must have k distinct elements so to eleminate the 
        // resudal sub-arrays with less than k distinct elements we minus
        // suppose k==4 
        // then while calculating the number of sub-arrays we also have
        // calculated for 1,2,3 distinct element sub-arrays we need to remove that from the ans
        // so we do the subtraction
        else ans=solve(nums,k)-solve(nums,k-1);
        return ans;
    }
};
int main(){
    vector<int> nums={1,2,1,2,3};
    Solution obj;
    int k=2;
    cout<<obj.subarraysWithKDistinct(nums,k);
}