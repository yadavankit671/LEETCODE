#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0]>=0) return -1;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==0) return nums[j];
            // -10,-8,-7,0,1,2,3,7,100
            if(abs(nums[i])>nums[j])i++;
            else if(nums[j]> abs(nums[i])) j--;
        }
        return -1;
    }
};
int main(){

}