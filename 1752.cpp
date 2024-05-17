#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int size=nums.size()-1;
        int rotatepos=-1;
        for(int i=0;i<size;i++){
            if(nums[i]>nums[i+1]) {
                rotatepos=i;
                break;
            }
        }
        if(rotatepos!=-1){
            for (int i=0;i<rotatepos;i++){
                if(nums[i]>nums[i+1] || nums[i]<nums[size]) return false;
            }
        }
        int i=(rotatepos==-1)?0:rotatepos+1;
        for(;i<size;i++){
            if(nums[i]>nums[i+1]) return false;
            if(rotatepos!=-1 && nums[rotatepos]<nums[i+1]) return false;
        }
        return true;
    }
};
int main(){
    vector<int> nums={2,1,3,4};
    Solution obj;
    cout<<obj.check(nums)<<endl;
}