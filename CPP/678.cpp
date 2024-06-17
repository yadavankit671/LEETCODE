#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        ios::sync_with_stdio(false);
        stack<int> st;
        stack<int> st2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]=='*') st2.push(i);
            else {
                if(!st.empty()) st.pop();
                else if(!st2.empty()) st2.pop();
                else return false;
            }
        }
        while(!st.empty() && !st2.empty()){
            if(st.top()>st2.top()) return false;
            st.pop();
            st2.pop();
        }
        if(st.size()>0) return false;
        return true; 
    }
};
int main(){
    string s="(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    Solution obj;
    cout<<endl<<obj.checkValidString(s);
}