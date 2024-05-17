#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        sort(nums.begin(),nums.end());
        int max_diff=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]>max_diff){
                max_diff=nums[i+1]-nums[i];
            }
        }
        return max_diff;
    }
};
int main(){

}