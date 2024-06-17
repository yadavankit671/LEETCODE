#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result;
        for(int i = 0; i < nums.size()-1;i+=2){
            if (nums.at(i)!=nums.at(i+1)){
                result=nums.at(i);
                return result;
            }
        }
        return nums.at(nums.size()-1);
    }
};
int main(){
    vector<int> v={4,1,2,1,2};
    Solution s;
    cout<<s.singleNumber(v);
}