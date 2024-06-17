#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> buffer(100,0);
        int maxnum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxnum) maxnum=nums[i];
            buffer[nums[i]]++;
        }
        int maximum=0;
        int result=0;
        for(int i=0;i<=maxnum;i++){
            if(buffer[i]>maximum){
                maximum=buffer[i];
                result=0;
                result+=maximum;
            }
            else if(buffer[i]==maximum)result+=buffer[i];
        }
        return result;
    }
};
int main(){
    Solution obj;
    vector<int> nums={1,2,2,3,1,4};
    cout<<obj.maxFrequencyElements(nums);
}