#include<bits/stdc++.h>
using namespace std;
class Solution{
    vector<int> productExceptSelf(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        vector<int> result;
        int product =1;
        int zero_count=0;
        for(auto x: nums ){
            if(x!=0) product *=x;
            else zero_count++;
        }
        if(zero_count>=2){
            return vector<int>(nums.size(),0);
        }
        else if(zero_count==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    result.push_back(0);
                }
                else result.push_back(product);
            }
        }
        else {
            for(int i=0;i<nums.size();i++){
                result.push_back(product/nums[i]);
            }
        }
        return result;
    }
};
int main(){
    vector<int> nums={-1,-1,1};
    Solution s;
}