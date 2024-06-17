#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        map<int,vector<int>> buffer;
        for(int i=0;i<nums.size();i++){
            buffer[nums[i]].push_back(i);
        }
        for(auto x: buffer){
            if(x.second.size()>=2){
                int n=x.second.size()-1;
                n=(n*(n+1))/2; // sum of natural numbers ...
                result+=n;
            }
        }
        return result;
    }
};
int main(){
    vector<int> nums={1,2,3,1,1,1,1,1,1,1,3};
    Solution obj;
    cout<<obj.numIdenticalPairs(nums);
}