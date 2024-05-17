#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int maxindex =-1;
        int minindex = -1;
        for(int i=0,j=0;j<nums.size();j++){
            if (nums.at(j)<minK || nums.at(j)>maxK){
                i=j+1; 
                continue;
            }
            if (nums.at(j)==maxK) maxindex=j; 
            if (nums.at(j)==minK) minindex=j;
            ans+=max((min(maxindex, minindex)-i+1),0);
        }
        return ans;
    }
};
int main(){
    vector<int> nums={1,1,1,1};
    Solution obj;
    cout<<obj.countSubarrays(nums,*min_element(nums.begin(),nums.end()),*max_element(nums.begin(),nums.end()));
}