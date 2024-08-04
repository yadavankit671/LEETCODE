#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    const int mod= 1e9+7;
    public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        for(int i = 0; i < n; ++i){
            int sum = 0;
            for(int j=i; j < n; ++j){
                sum += nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        int ans = 0;
        while(left <= right){
            ans = (ans + arr[left - 1]) % mod;
            left++;
        }
        return ans;
    }
};
int main(){

}