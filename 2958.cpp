#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        if(nums.size()==k) return k;
        int result=0;
        int left=0;
        int right=0;
        map<int,int> buff;
        while(right<nums.size()){
            buff[nums.at(right)]++;
            if(buff[nums.at(right)]>k){
                while(nums.at(left)!=nums.at(right)){
                    buff[nums.at(left)]--;
                    left++;
                }
                //buff[nums.at(right)]>k ki bharpai
                buff[nums.at(left)]--;
                left++;
            }
            result=max(result,right-left+1);
            right++;
        }
        return result;
    }
};
int main(){
    vector<int> nums={2,2,1,2};
    int k=1;
    Solution obj;
    cout<<obj.maxSubarrayLength(nums,k);
}