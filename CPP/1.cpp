#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        unordered_map<int,int> buffer;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int temp=target-nums.at(i);
            if(buffer.find(temp)!=buffer.end()){
                result.push_back(min(buffer[temp],i));
                result.push_back(max(buffer[temp],i));
                return result;
            }
            buffer[nums.at(i)]=i;
        }
        return {-1,-1};
    }
};
int main(){
    Solution s;
    vector <int> num;
    int target;
    //take input 
    s.twoSum(num, target);
}