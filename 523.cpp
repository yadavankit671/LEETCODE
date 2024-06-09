#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixSum=0;
        unordered_map<int,int> mp;
        mp[0]=-1; // 0 indexed mein 1- (-1) ==2 // 0,1 --> 2 elements
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            int r= (k==0)? prefixSum: prefixSum%k;
            if(mp.count(r)){
                //cout<<mp.count(r)<<"\t"<<mp[r]<<"\t"<<i<<"\t"<<i-mp[i]<<endl;
                if(i-mp[r]>1) return true;  
            }
            else mp[r]=i;
        }
        return false;
    }
};
int main(){

}