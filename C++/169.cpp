#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                ans=nums[i];
                count=1;
            }
            else if(nums[i]==ans) count++;
            else count--;
        }
        return ans;
    }
};
int main(){

}