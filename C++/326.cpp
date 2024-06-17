#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<1) return false; 
        for(int i=0;i<n;i++){
            int temp=pow(3,i);
            if(temp==n) return true;
            if(temp>n) break;
        }
        return false;
    }
};
int main(){

}