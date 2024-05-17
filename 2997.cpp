#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = 0;
        int xr = nums.at(0);
        for (int i=1;i<nums.size();i++){
            xr=xr^nums.at(i);
        }
        if(xr==k) return 0;
        
    }
};
int main(){
    vector<int> nums={2,0,2,0};
    int k=0;
    Solution obj;
    cout<<obj.minOperations(nums,k)<<endl;
}