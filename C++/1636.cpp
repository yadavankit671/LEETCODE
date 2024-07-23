#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // -100 <= nums[i] <= 100
        vector<pair<int, int>> arr(201, {0, 0});
        for (int num : nums) {
            int idx = num <= 0 ? abs(num) : 100 + num;
            arr[idx].first++;
            arr[idx].second = num;
        }
        sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });
        int index = 0;
        for (const auto& p : arr) {
            for (int i = 0; i < p.first; ++i) {
                nums[index++] = p.second;
            }
        }
        return nums;
    }
};
int main(){

}