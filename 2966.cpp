#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int size=nums.size();
        for(int i=0;i<size;){
            vector<int> temp;
            int j=i;
            for(;j<size &&  j<i+3;j++){
                if(!temp.empty() && nums[j]-temp.at(temp.size()-1)>k) return {};
                else temp.push_back(nums[j]);
            }
            if(temp.at(temp.size()-1)-temp.at(temp.size()-2)>k) return {};
            if(temp.at(temp.size()-1)-temp.at(0)>k) return {};
            i=j;
            result.push_back(temp);
        }
        return result;
    }
};
int main(){

}