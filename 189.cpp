#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0) return;
        k=k%nums.size();
        reverse(nums.begin(),nums.end()); //[7,6,5,4,3,2,1]
        reverse(nums.begin(),nums.begin()+k); //[5,6,7,4,3,2,1]
        reverse(nums.begin()+k,nums.end()); //[5,6,7,1,2,3,4]
    }
};
int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    int k=3;
    Solution obj;
    obj.rotate(nums,k);
    for(auto x: nums) cout<<x<<",";
}
//33/7=28