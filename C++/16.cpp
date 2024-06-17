#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closet=INT_MAX;
        int size=nums.size();
        int res=0;
        for(int i=0;i<size;i++){
            int j=i+1,k=size-1;
            while(j<k){
                int temp=nums[i]+nums[j]+nums[k];
                if(temp==target)return target;
                else if(abs(target-(temp))<abs(closet)){
                    closet=target-temp;
                    res=temp;
                }
                if(temp>target)k--;
                else j++;
            }
        }
        return res;
    }
};
int main(){

}