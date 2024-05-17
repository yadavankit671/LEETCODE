#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int smallest;
        sort(nums.begin(), nums.end());
        int i=0;
        while(i<nums.size()) {
            if(nums.at(i)>0){
                smallest=nums.at(i++);
                break;
            }
            i++;
        }
        if(smallest!=1) return 1;
        for(;i<nums.size();i++){
            if(smallest!=nums.at(i) && smallest+1!=nums.at(i)){
                return smallest+1;
            }
            smallest=nums.at(i);
        }
        return (nums.at(nums.size()-1)<0)?1:nums.at(nums.size()-1)+1;
    }
};
int main(){
    vector<int> nums={2147483647,2147483646,2147483645,3,2,1,-1,0,-2147483648};
    Solution obj;
    cout<<obj.firstMissingPositive(nums);
}