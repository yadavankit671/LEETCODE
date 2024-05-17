#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        stack<int> stk;
        int i=0;int j=nums.size()-1;
        stk.push(nums.at(i++)+nums.at(j++));
        while(i<j){
            int sum=nums.at(i++)+nums.at(j++);
            if(stk.top()<sum){
                stk.push(sum);
            }
        }
        return stk.top();
    }
};
int main(){

}