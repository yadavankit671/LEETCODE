#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int countPairs(vector<int>& nums, int target) {
        int res=0;
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
                if(nums[i]+nums[j]<target) res++;
        return res;
    }
};
int main(){
    // -1,1,1,2,3 == 2
    vector<int> nums={-6,2,5,-2,-7,-1,3};
    Solution obj;
    cout<<obj.countPairs(nums,-2);
}