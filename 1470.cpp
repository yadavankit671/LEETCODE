#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        for(int i=0;i<n;i++){
            result.push_back(nums[i]);
            result.push_back(nums[n+i]);
        }
        return result;
    }
};
int main(){
    vector<int> result={1,2,3,4,4,3,2,1};
    Solution obj;
    result=obj.shuffle(result,4);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<",";
    }
}