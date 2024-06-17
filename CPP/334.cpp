#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if( nums.size()<3 ) return false;
        int x=INT_MAX;
        int y=INT_MAX;
        for(int n : nums){
            if(n<=x) x=n;
            else if(n<=y) y=n;
            else return true;
        }
        return false;
    }
};
int main(){

}