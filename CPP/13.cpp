#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int RomanToInteger(string s){
        vector <int> str(256,0);
        int size=s.length();
        int integer=0;
        str['I']=1;str['V']=5;str['X']=10;str['L']=50;str['C']=100;str['D']=500;str['M']=1000;
        for(int i=size-1;i>=0;i--){
            if(i>0 && (str[s[i]]>str[s[i-1]])){
                integer=integer+str[s[i]]-str[s[i-1]];
                i--;
            }
            else{
                integer=integer+str[s[i]];
            }
        }
        return integer;
    }
};
int main(){
    Solution S;
    string str="XC";
    cout<<S.RomanToInteger(str);
}