#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int count=0;
        long long sum =0,sacrifice=INT_MAX;
        for( auto elem : nums){
            if((elem^k) > elem){
                sum+=elem^k;
                count++;
                sacrifice = min<long long>(sacrifice, (elem^k)-elem);
            }
            else {
                sum += elem;
                sacrifice = min<long long>(sacrifice,elem-(elem^k));
            }
        }
        if (count %2==0) return sum;
        return sum-sacrifice;
    }
};
int main(char* args){

}