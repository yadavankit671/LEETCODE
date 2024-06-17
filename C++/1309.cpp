#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string freqAlphabets(string s) {
        string result="";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='#'){
                i--;
                int one=s[i]-'0';
                i--;
                int ten=s[i]-'0';
                ten=ten*10+one;
                result=char('a'+ten-1)+result;
            }
            else {
                int temp=s[i]-'0';
                result=char(temp+'a'-1)+result;
            }
        }
        return result;
    }
};
int main(){
    string str="1326#";
    Solution obj;
    cout<<obj.freqAlphabets(str);
}