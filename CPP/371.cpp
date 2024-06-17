#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int getSum(int a,int b){
        vector<int>result={a,b};
        long sum=accumulate(result.begin(),result.end(),0);
        if(sum<INT_MIN) return INT_MIN;
        if(sum>INT_MAX) return INT_MAX;
        return int(sum);
    }
};
int main(){
    Solution s;
    cout<<s.getSum(4,5);
}