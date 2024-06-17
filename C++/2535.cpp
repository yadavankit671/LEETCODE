#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    int getDigitSum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum=accumulate(nums.begin(),nums.end(),0);
        int digitSum=0;
        for(auto x: nums){
            digitSum+=getDigitSum(x);
        }
        return elementSum-digitSum;
    }
};
int main(){

}