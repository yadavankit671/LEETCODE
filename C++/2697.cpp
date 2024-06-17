#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(s[start]<s[end]) s[end]=s[start];
            else if (s[end]<s[start]) s[start]=s[end];
            start++;end--;
        }
        return s;
    }
};
int main(){

}