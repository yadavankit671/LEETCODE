#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7) return true;
        if(n<10) return false;
        int temp=0;
        while(n>0){
            temp=temp+((n%10)*(n%10));
            n=n/10;            
        }
        if(isHappy(temp)) return true;
        return false;
    }
};
int main(){
    Solution s;
    cout<<s.isHappy(19)<<endl;
}