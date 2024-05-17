#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int differenceOfSums(int n, int m) {
        if(m==1) return -1*(n*(n+1)/2);
        int div=0;
        int ndiv=n*(n+1)/2;
        int k=m;
        while(m<=n){
            div+=m;
            m+=k;
        }
        return ndiv-(2*div);
    }
};
int main(){
    Solution obj; //15  9  102  // 1+2+3+4=10  
    int n=4;
    int m=2;
    cout<<obj.differenceOfSums(n,m)<<endl;
}