#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0){
            return 0;
        }
        int i=0;
        for(;i<nums.size();i++){
            if(target==nums.at(i))
            return i;
            if(target<nums.at(i))
            return i;
        }
        return i;
    }
};
int main(){

}