#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortSentence(string s) {
        map<int,string> buffer;
        string temp="";
        int cnt=(s.at(s.length()-1))-'0';
        for(int i=s.length()-2;i>=0;i--){
            if(s[i]!=' '){
                temp=s[i]+temp;
            }
            else {
                buffer[cnt]=temp;
                i--;
                cnt=s[i]-'0';
                temp="";
            }
        }
        buffer[cnt]=temp;
        cnt=1;
        temp="";
        for(auto x: buffer){
            temp+=x.second;
            temp+=" ";
        }
        temp.erase(temp.length()-1);
        return temp;
    }
};
int main(){
    string str="Myself2 Me1 I4 and3";
    Solution obj;
    cout<<obj.sortSentence(str);
}