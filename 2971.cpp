#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long maximum=-1;
        long long p=nums.at(0);
        for(int i=1;i<nums.size();i++){
            if(p>nums.at(i))
            maximum=max(p+nums.at(i),maximum);
            p+=nums[i];
        }
        return maximum;
    }
};
int main(){
    vector<int> nums={1,12,1,2,5,50,3};
    Solution obj;
    cout<<obj.largestPerimeter(nums)<<endl;
}