#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        double palin=0;
        int temp=x;
        while(temp>0){
            palin=palin*10+temp%10;
            temp=temp/10;
        }
        if(palin==x)
        return true;
        else
        return false;
    }
};
int main(){
    int x=121;
    Solution obj;
    cout<<obj.isPalindrome(x)<<endl;
}