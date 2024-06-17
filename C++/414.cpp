#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max<int> (nums[0],nums[1]);
        int x=INT_MIN;
        int y=INT_MIN;
        int z=INT_MIN;
        bool minFlag=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==INT_MIN) minFlag=true;
            if(nums[i]>x){
                z=y;
                y=x;
                x=nums[i];
            }
            if(nums[i]>y && nums[i]<x){
                z=y;
                y=nums[i];
            }
            if(nums[i]>z && nums[i]<x && nums[i]<y){
                z=nums[i];
            }
        }
        if(minFlag && x!=INT_MIN && y!=INT_MIN) return INT_MIN;
        if (z==INT_MIN) return x;
        return z;
    }
};
int main(){
    vector<int> nums={1,2,-2147483648};
    Solution obj;
    cout<<obj.thirdMax(nums)<<endl;
}