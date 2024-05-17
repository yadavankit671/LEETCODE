#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result=nums.size();
        stack <pair<int,int>> stk;
        stk.push(make_pair(nums[0],1));
        for(int i=1;i<nums.size();i++){
            if(stk.top().first==nums[i]){
                if(stk.top().second <2) stk.top().second++;
                else result--;
            }
            else stk.push(make_pair(nums[i],1));
        }
        while(nums.size()!=result){
            nums.pop_back();
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(stk.top().second==2){
                nums[i]=stk.top().first;
                i--;
                nums[i]=stk.top().first;
                stk.pop();
            }
            else {
                nums[i]=stk.top().first;
                stk.pop();
            }
        }
        return result;
    }
};
int main(){        // 0,0,1,1,2,3,3    ->9-(4-2)- ==> 7
    vector<int> nums={0,0,0,0,1,1,1,1,2,3,3};
    Solution obj;
    cout<<nums.size()<<endl;
    cout<<obj.removeDuplicates(nums)<<endl;
    for(auto x: nums) cout<<x<<",";
}