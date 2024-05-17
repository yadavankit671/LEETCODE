#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> leeftRiightDifference(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        int size = nums.size();
        int lsum=0;
        int rsum=0;
        for(int i=0;i<size;i++){
            left.push_back(lsum);
            lsum+=nums[i];
            right.push_back(rsum);
            rsum+=nums[size-1-i];
        }
        for(int i=0;i<size;i++){
            nums[i]=abs(left[i]-right[size-1-i]);
        }
        return nums;
    }
};
int main(){
    vector<int> nums={10,4,8,3};
    Solution obj;
    vector<int> result=obj.leeftRiightDifference(nums);
    cout<<"Result :";
    for(auto x: result)cout<<x<<",";
}