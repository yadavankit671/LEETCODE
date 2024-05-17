#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int depth = 0;
        for (char c : s){
            if(c=='(') st.push(c);
            else if(c==')')st.pop();
            depth=max<int>(depth,st.size());
        }
        return depth;
    }
};
int main(){

}