#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                start=mid+1;
            }
            else
                end=mid-1;
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> nums={-9,12};
    cout<<s.search(nums,9);
}