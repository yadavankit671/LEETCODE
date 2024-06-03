#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int j=0;
        int covered=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==t[j]) covered++,j++;
        }
        return t.length()-covered;
    }
};
int main(){
    //s = "coaching", t = "coding"
    string s="lbg";
    string t="g";
    Solution obj;
    cout<<obj.appendCharacters(s,t)<<endl;

}