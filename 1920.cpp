#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> temp=nums;
        for(int i=0;i<nums.size();i++){
            nums.at(i)=temp.at(temp.at(i));
        }
        return nums;
    }
};
int main(){
    Solution s;
    vector<int> nums={0,2,1,5,3,4};
    vector<int> temp=s.buildArray(nums);
    for(int i=0;i<temp.size();i++)
    cout<<temp[i]<<endl;
}