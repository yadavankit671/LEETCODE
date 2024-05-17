#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool signAllowed=true;
    bool decimal_allowed=true;
    bool e_allowed=true;
    bool validChar(char x){
        bool result=true;
        if (x!='e'&&x!='E'){
            if(x!='+'&& x!='-'){
                if(x!='.' && !isdigit(x)) result=false;
            }
        }
        return result;
    }
    bool decimalCheck(string s,int index){
        if(!decimal_allowed) return false;
        if(!e_allowed && index==s.length()-1) return false;
        if(index!=0 && (s[index-1]=='+'||s[index-1]=='-') && index==s.length()-1) return false;
        if(index==0 && s[index+1]=='e' || s[index+1]=='E') return false;
        decimal_allowed=false;
        return true;
    }
    bool echeck(string s,int index){
        if(!e_allowed) return false;
        if(index==0) return false;
        if(!isdigit(s[index-1]) && s[index-1]!='.') return false;
        if(index==s.length()-1) return false;
        decimal_allowed=false;
        if(s[index+1]=='+'|| s[index+1]=='-')
            signAllowed=true;
        e_allowed=false;
        return true;
    }
    bool signCheck(string s,int index){
        if(signAllowed==false) return false;
        if(index!=0 && (s[index-1]!='e' && s[index-1]!='E') ) return false;
        if(index==s.length()-1) return false;
        if(s[index+1]=='-'|| s[index+1]=='+') return false;
        signAllowed=false;
        return true;
    }
public:
    bool isNumber(string s) {
        if(s.length()==1 && !isdigit(s[0])) return false; 
        bool result =true;
        int i=0;
        for(;i<s.length();i++){
            result=(result)?validChar(s[i]):false;
            if(result==false ) break;
            if(s[i]=='+' || s[i]=='-') result=signCheck(s,i);
            else if(s[i]=='e' || s[i]=='E') result=echeck(s,i);
            else if(s[i]=='.') result=decimalCheck(s,i);
        }
        return result;
    }
};
int main(){
    string str="3E+7";
    Solution obj;
    cout<<obj.isNumber(str);
}
