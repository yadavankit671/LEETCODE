#include<bits/stdc++.h>
using namespace std;
/* 
---------------- Brute Force ----------------
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            stack<char> st;
            for(int j = i; j < s.size(); j++){
                if(s[j] == '(') st.push('(');
                else {
                    if(st.empty()) break;
                    st.pop();
                }
                if(st.empty()) result = max(result, j - i + 1);
            }
        }
        return result;
    }
};
*/
class Solution {
    public:
    int longestValidParentheses(string s){
        int result = 0;
        vector<int> indices;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') indices.push_back(i);
            else {
                if(!indices.empty() && s[indices.back()] == '(') 
                    indices.pop_back();
                else indices.push_back(i);
            }
        }
        if(indices.empty()) return s.length();
        result = indices[0]; // handles 0 to first invalid index
        for(int i = 1; i < indices.size(); i++){  // handles all valid substrings between invalid indices
            result = max(result, indices[i] - indices[i - 1] - 1);
        }
        result = max<int>(result, s.length() - indices.back() - 1); // handles last invalid index to end of string
        return result;
    }
};
int main(){
    string s=")()())";
    Solution obj;
    cout<<obj.longestValidParentheses(s);
}