#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.length();
        if(len == 0) return 0;
        if(len==1) return 1;
        vector<int> characters(256,0);
        for(int i=0;i<s.length();i++) characters[s[i]]++;
        int length=0;
        bool flag=false;
        for(int i=0;i<characters.size();i++) {
            if(characters[i]>2 && characters[i]%2!=0){characters[i]--;flag=true;}
            if(characters[i]%2==0) length+=characters[i];
            if(characters[i]%2==1) flag=true;
        }
        return (flag==true) ? length+1:length;
    }
};
int main(){
    string s="ccc";
    Solution obj;
    cout<<obj.longestPalindrome(s);
}