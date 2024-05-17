#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]<97){
                s[i]=s[i]+('a'-'A');
            }
        }
        return s;
    }
};
int main(){
    string str="HELLO";
    Solution obj;
    cout<<obj.toLowerCase(str)<<endl;
}