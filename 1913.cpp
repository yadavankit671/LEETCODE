#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int min=INT_MAX,secmin=INT_MIN,max=INT_MIN,secmax=INT_MIN;
        for(auto x: nums){
            if(x<min){
                secmin=min;
                min=x;
            }
            else if(x<secmin) secmin=x;
            if(x>max){
                secmax=max;
                max=x;
            }
            else if(x>secmax) secmax=x; 
        }
        return (max*secmax)-(min*secmin);
    }
};
int main(){

}