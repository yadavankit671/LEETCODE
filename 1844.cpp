#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceDigits(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                s[i]=s[i-1]+s[i]-'0';
            }
        }
        return s;
    }
};
int main(){
    string str="a2c1e1";
    Solution obj;
    cout<<obj.replaceDigits(str);
}