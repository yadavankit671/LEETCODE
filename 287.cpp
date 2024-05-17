#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==1) return *nums.begin();
        int i=0;
        while(i<nums.size()){
            if(nums[i]=i) i++;
            else if(nums[i]==nums[nums[i]])return nums[i];
            else swap(nums[i],nums[nums[i]]);
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,3,4,2,2};
    cout<<s.findDuplicate(nums);

}