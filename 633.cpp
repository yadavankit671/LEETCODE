#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        long long i=0,j=sqrt(c);
        while(i<=j){
            long long temp=i*i+j*j;
            if(temp==c) return true;
            else if(temp>c) j--;
            else i++;
        }
        return false;
    }
};
int main(){
    Solution obj;
    cout<<obj.judgeSquareSum(8)<<endl;
    return 0;
}