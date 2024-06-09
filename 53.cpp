#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=INT_MIN;
        int temp=0;
        for(int x : nums){
            temp+=x;
            sum=max(sum,temp);
            if(temp<0)  temp=0;
        } 
        return sum;
    }
};
int main(){

}