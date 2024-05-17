#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        map<int, int> buffer;
        sort(temp.begin(), temp.end());
        for(int i=temp.size()-1;i>=0;i--){
            buffer[temp[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            temp[i]=buffer[nums[i]];
        }
        return temp;
    }
};
int main(){
    vector<int> nums={8,1,2,2,3};
    Solution obj;
    vector<int> res=obj.smallerNumbersThanCurrent(nums);
    for(auto x: res)cout<<x<<endl;
}