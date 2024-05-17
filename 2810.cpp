#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string finalString(string s) {
        string result="";
        for(int i=0; i<s.length(); i++){
            if(s[i]=='i'){
                reverse(result.begin(), result.end());
            }
            else result+=s[i];
        }
        return result;
    }
};
int main(){
    string s="string";
    Solution obj;
    cout<<obj.finalString(s)<<endl;
}