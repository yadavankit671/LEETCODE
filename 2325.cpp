#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,int> code;
        int k=1;
        for(int i=0;i<key.length();i++) {
            if(code[key[i]]==0 && key[i]!=' '){
                code[key[i]]=k++;
            }
            else continue;
        }
        string result="";
        for(int i=0;i<message.length();i++){
            if(message[i]!=' '){
                result+=char(code[message[i]]+'a'-1);
            }
            else result+=" ";
        }
        return result;
    }
};
int main(){
    string key = "eljuxhpwnyrdgtqkviszcfmabo";
    string message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
    Solution obj;
    cout<<obj.decodeMessage(key,message);
}