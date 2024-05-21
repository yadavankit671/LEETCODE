#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int n=1<<nums.size();
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    temp^=nums[j];
                }
            }
            ans+=temp;
        }
        return ans;
    }
};
int main(){
    vector<int> nums={5,1,6};
    Solution obj;
    cout<<obj.subsetXORSum(nums)<<endl;
}