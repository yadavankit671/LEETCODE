#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1) return nums.at(0);
        vector<int> temp(nums.size()-1,0);
        for(int i=0;i<temp.size();i++){
            int sum=nums.at(i)+nums.at(i+1);
            temp.at(i)=sum%10;
        }
        return triangularSum(temp);
    }
};
int main(){

}