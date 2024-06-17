#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n!=1 && n%2!=0 || n<=0) return false;
        int k=-1;
        int temp=n;
        while(n>0){
            n/=2;
            k++;
        }
        if(pow(2,k)==temp) return true;
        return false;
    }
};
int main(){
    Solution s;
    cout<<s.isPowerOfTwo(1);
}