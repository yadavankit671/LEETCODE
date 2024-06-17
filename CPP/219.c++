#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        if (nums.size()==1 || nums.size()==0) return false;
        unordered_map <int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                if(abs(i-mp[nums[i]])<=k) return true;
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};
int main(){
    vector<int> nums={1,2,3};
    Solution s;
    if (s.containsNearbyDuplicate(nums,2)) cout<<"Contains Duplicate"<<endl;
    else cout<<"NO Duplicate"<<endl;
}