#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int index = 0;
        while(index < s.length()){
            if(s[index]=='('){
                st.push(index++);
            }
            else if(s[index]==')'){
                reverse(s.begin()+st.top()+1,s.begin()+index);
                s.erase(index,1);
                s.erase(st.top(),1);
                st.pop();
                index--;
            }
            else index++;
        }
        return s;
    }
};
int main(){
    Solution obj;
    string s="(ed(et(oc))el)";
    cout<<obj.reverseParentheses(s)<<endl;
}