#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string var){
        string temp=var;
        reverse(temp.begin(),temp.end());
        return (temp==var)?true:false;
    }
    string longestPalindrome(string s) {
        if (s.length()==1) return s;
        string result="";
        for(int i=0;i<s.length();i++){
            string temp;
            for(int j=s.length()-1;j>i;j--){
                if(s[j]==s[i]){
                    temp=s.substr(i,j-i+1);
                    if(isPalindrome(temp)){
                        if(temp.length()>result.length()){
                            result=temp;
                        }
                        break;
                    }
                    
                }
            }
        }
        if(result.length()==0){
            result+=s[0];
        }
        return result;
    }
};
int main(){

}