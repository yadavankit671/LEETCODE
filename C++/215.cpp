#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q(nums.begin(),nums.begin()+k);
        for (int i=k;i<nums.size();i++){
            if(nums[i]>q.top()){
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};
int main(){
    Solution obj;
    vector<int> nums={3,2,3,1,2,4,5,5,6};
    cout<<obj.findKthLargest(nums,4);
}