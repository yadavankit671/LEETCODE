#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length()==0) return 0;
        int result = INT_MIN;
        stack<int> st;
        int i=0;
        for(;i<s.length();i++){
            if(s[i]=='(') st.push(i);
        }
        return result;
    }
};
int main(){
    string s="()(()(((())))";
    Solution obj;
    cout<<obj.longestValidParentheses(s);
}