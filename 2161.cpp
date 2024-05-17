#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> q;
        vector<int> result;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot) q.push(nums[i]);
            else if(nums[i]==pivot) count++;
            else result.push_back(nums[i]);
        }
        while(count){
            result.push_back(pivot);
            count--;
        }
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
int main(){
    vector<int> nums={9,12,5,10,14,3,10};
    int pivot=10;
    //result ={9,5,3,10,10,12,14};
    Solution obj;
    vector<int> result=obj.pivotArray(nums,pivot);
    for(auto x: result) cout<<x<<",";
}