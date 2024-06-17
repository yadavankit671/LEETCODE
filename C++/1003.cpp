#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='b') v.push_back(s[i]);
            else{
                if(v.empty()) return false;
                if(v.at(v.size()-1)!='b') return false;
                else v.pop_back();
                if(v.empty()) return false;
                if(v.at(v.size()-1)!='a') return false;
                else v.pop_back();
            }
        }
        if(v.size()==0) return true;
        return false;
    }
};
int main(){
    string s="abcabcababcc";
    Solution obj;
    cout<<obj.isValid(s)<<endl;
}