#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = -1;
        map<int,int> buffer;
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==1) sum++;
            else sum--;
            if(sum==0) result=max(result,i+1);
            if(buffer.find(sum)==buffer.end()) buffer[sum]=i;
            else result=max(result,i-buffer[sum]);
        }
        return result;
    }
};
int main(){
    vector<int> nums={0,0,1,0,0,0,1,1};
    Solution obj;
    cout<<obj.findMaxLength(nums)<<endl;

}
/*

[0, 1, 1, 1, 1, 1, 0, 1, 0, 1]
[1, 1, 0, 0, 1, 1, 0, 1, 0, 1]
[0, 0, 0, 1, 1, 0, 0, 1, 1, 0]
[1, 0, 1, 1, 0, 1, 1, 1, 0, 1]
[0, 0, 0, 1, 1, 0, 1, 1, 1, 1]
[1, 0, 0, 0, 1, 1, 0, 1, 1, 0]
[0, 0, 1, 0, 0, 1, 1, 1, 0, 1]
[0, 1, 0, 1, 0, 0, 1, 0, 0, 0]
[1, 1, 1, 1, 1, 1, 1, 1]

*/