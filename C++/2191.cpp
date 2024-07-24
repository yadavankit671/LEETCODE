#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    int getVal(vector<int>&mapping, int val){
        int res = 0;
        string value = to_string(val);
        for(int i = 0; i < value.size(); ++i){
            res = res * 10 + mapping[value[i] - '0'];
        }
        return res;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> map;
        for(int i = 0; i < nums.size(); ++i){
            map.push_back({nums[i],getVal(mapping,nums[i])});
        }
        sort(map.begin(),map.end(),[]
            (pair<int,int> &a, pair<int,int> &b){
                return a.second < b.second;
            }
        );
        for(int i = 0; i < nums.size(); ++i){
            nums[i] = map[i].first;
        }
        return nums;
    }
};
int main(){

}