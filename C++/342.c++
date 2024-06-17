#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n<4) return false;
        if(n%4!=0) return false;
        for(int i=1;i<15;i++){
            if(pow(4,i)==n) return true;
        }
        return false;
    }
};
int main(){
    int n=4194304;
    Solution obj;
    cout<<obj.isPowerOfFour(n);
}