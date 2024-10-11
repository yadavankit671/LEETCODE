#include<bits/stdc++.h>
using namespace std;
class NumArray {
    private :
    vector<int> prefixSum;
    vector<int> buffer;
public:
    NumArray(vector<int>& nums) : buffer(nums){
        prefixSum.resize(nums.size());
        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        for(int i = 0; i < nums.size(); i++) cout<<prefixSum[i]<<" ";
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right] - prefixSum[left] + buffer[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
int main(){

}