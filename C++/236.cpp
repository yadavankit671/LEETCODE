#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isUgly(int n) {
        if (n==1) return true;
        if(n%2!=0 && n%3!=0 && n%5!=0) return false;
        if(n%2==0) n/=2;
        if(n%3==0) n/=3;
        if(n%5==0) n/=5;
        return isUgly(n);
    }
};
int main(){

}