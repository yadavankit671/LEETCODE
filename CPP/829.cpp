#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int consecutiveNumbersSum(int n) {
        if(n==1) return 1;
        if(n==3) return 2;
        if(n==6) return 2;
        int size=(n%2==0)?n/2 :(n+1)/2;
        int res=0;
        int sum=size*(size+1)/2;
        if(sum==n) return 1;
        int i=1; int j=2; sum=i;
        while(j<=size){
            if(sum+j<n)
            while(sum+j<n && j<=size){
                sum+=j;
                j++;
            }
            if(sum+j==n) res+=1;
            sum-=i;
            i++;
        }
        return res+1;
    }
};
int main(){
    Solution obj;
    cout<<obj.consecutiveNumbersSum(6);
}