#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<pair<char,char>> buffer(256,make_pair('\0','\0'));
        string res;
        for(int i=0;i<s.length();i++){
            if(buffer[s[i]].first && buffer[s[i]].first!=t[i]) return false;
            if(buffer[t[i]].second && buffer[t[i]].second!=s[i]) return false;
            buffer[s[i]].first = t[i];
            buffer[t[i]].second = s[i];
        }
        return true;
    }
    void print(vector<pair<char,char>> buffer){
        cout<<"Buffer :";
        for(int i='a';i<='z';i++){
            if(buffer[i].first=='\0') cout<<0<<" "<<0;
            cout<<buffer[i].first<<" "<<buffer[i].second;
            cout<<",";
        }
        cout<<endl;
    }
};
int main(){
    string s="egg";
    string t="add";
    Solution obj;
    if(obj.isIsomorphic(s,t)) cout<<"Isomorphic String ";
    else cout<<"Not Isomorphic String ";
}