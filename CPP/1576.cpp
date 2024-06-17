#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    char chooseNext(char a,char b){
        for(int i=0;i<26;i++){
            if(char(i+'a')!=a && char(i+'a')!=b) return char(i+'a');
        }
        return ' ';
    }
public:
    string modifyString(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]=='?'){
                char a,b;
                if(i==0) a=' ';
                else a=s[i-1];
                if(i==s.length()-1) b=' ';
                else b=s[i+1];
                s[i]=chooseNext(a,b);
            }
        }
        return s;
    }
};
int main(){

}