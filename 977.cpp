#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums){
        int size=nums.size()-1;
        vector<int> result(size+1);
        int left=0;
        int right=size;
        for(int i=size; i>=0; i--) {
            int l=pow(nums[left],2);
            int r=pow(nums[right],2);
            if(l>=r){
                result[i]=l;
                left++;
            }
            else {
                result[i]=r;
                right--;
            }
        }
        return result;
    }
};
int main(){
    vector<int> nums={-4,-1,0,3,10};
    Solution obj;
    vector<int> result=obj.sortedSquares(nums);
    for(auto x: result) cout<<x<<",";
}