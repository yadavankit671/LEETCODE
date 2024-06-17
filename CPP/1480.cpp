#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        for (int i=0; i<nums.size();i++){
            sum+=nums[i];
            nums[i]=sum;
        }
        return nums;
    }
};
int main(){
    vector<int> nums={1,2,3,4};
    Solution obj;
    vector<int> result=obj.runningSum(nums);
    for(int i=0;i<result.size();i++){cout<<result[i]<<endl;}
}