#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int size = nums.size();
        int oneCount = accumulate(nums.begin(),nums.end(),0);
        int sum = accumulate(nums.begin(),nums.begin() + oneCount, 0);
        int maxOnes = sum;
        int start = 0;
        int end = oneCount;
        while(end < 2 * size){
            sum -= nums[start % size];
            sum += nums[end % size];
            maxOnes = max(maxOnes, sum);
            start++;
            end++;
        }
        return oneCount - maxOnes;
    }
};
int main(){
    vector<int> nums = {0,1,1,1,0,0,1,1,0};
    Solution obj;
    cout << endl <<obj.minSwaps(nums) << endl;
}