#include<iostream>
using namespace std;
class Solution {
    public :
    int stack[10000];
    int pos=1;
    bool isValid(string s){
        if(s.length()==0){
            return true;
        }
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stack[pos++]=s[i];
            }
            else if(c==1+stack[pos-1] || c==2+stack[pos-1]){
                pos--;
            }
            else{
                return false;
            }
        }
        return (pos==1)?true:false;
    }
};
int main(){
    Solution s;
    string str="{[]}[]";
    cout<<s.isValid(str);
}

