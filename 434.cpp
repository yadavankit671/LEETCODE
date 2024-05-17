#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        if(s.length()==0) return 0;
        int i=0;
        int ans=0;
        for(;i<s.length();i++){
            if(i+1<s.length() && s.at(i)!=' ' && s.at(i+1)==' ' ) {ans++;}
            if(i+1==s.length() && s.at(i)!=' ') ans++;
        }
        return ans;
    }
};
int main(){
    string s="Hello";
    Solution obj;
    cout<<obj.countSegments(s);
}