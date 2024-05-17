#include<bits/stdc++.h>
using namespace std;
void print(vector<int> nums){
    if(nums.size()==0) {
        cout<<"Empty List"<<endl;
        return;
    }
    cout<<"List : "<<nums[0];
    for(int i=1;i<nums.size();i++) cout<<","<<nums[i];
    cout<<endl;
}
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(auto x: nums){
            if(nums[abs(x)-1]<0) ans.push_back(abs(x));
            else nums[abs(x)-1]*=-1;
        }
        return ans;
    }
};
int main(){
    vector<int> nums={4,3,2,7,8,2,3,1};
    Solution obj;
    vector<int> res=obj.findDuplicates(nums);
    print(res);
}