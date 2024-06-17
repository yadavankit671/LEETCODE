#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        pair<int,int> mini(INT_MAX,-1);
        pair<int,int> maxi(INT_MIN,-1);
        int size = nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]<mini.first) mini.first=nums[i],mini.second=i;
            if(nums[i]>maxi.first) maxi.first=nums[i],maxi.second=i;
        }
        int result=0;
        result=max(mini.second,maxi.second)+1;
        result=min(result,size-min(mini.second,maxi.second));
        result=min(result,min(mini.second,maxi.second)+1+size-max(mini.second,maxi.second));
        return result;
    }
};
int main(){
    vector<int> nums={0,-4,19,1,8,-2,-3,5};
    Solution obj;
    cout<<obj.minimumDeletions(nums)<<endl;
}