#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int climbStairs(int n){
        int cache[n+1];
        cache[n]=1;
        cache[n-1]=1;
        for (int i=n-2;i>=0;i--){
            cache[i]=cache[i+1]+cache[i+2];
        }
        return cache[0];
    }
};
int main(){
    Solution s;
    cout<<s.climbStairs(5);
}