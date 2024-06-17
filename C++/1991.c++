#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
            /*
            [1,2,3,4, 5, 6,7]
        L-->[0, 1, 3,  6,10,15,21]
        r-->[27,25,22,18,13,7, 0]
            */
    int findMiddleIndex(vector<int>& nums) {
        int leftsum=0;
        int rightSum= accumulate(nums.begin(), nums.end(),0);
        for(int i=0;i<nums.size();i++){
            rightSum-=nums[i];
            cout<<rightSum<<"\t"<<leftsum<<endl;
            if(leftsum==rightSum) return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> v={1,2,3,4,5,6,7};
    s.findMiddleIndex(v);
}