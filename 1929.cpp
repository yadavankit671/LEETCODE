#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result(2*nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            result[i] = nums[i];
            result[i+nums.size()] =nums[i];
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> res={1,2,3};
    res=s.getConcatenation(res);
    for(int i=0; i<res.size(); i++)
    cout<<res[i]<<endl;
}