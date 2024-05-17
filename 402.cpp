#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length()) return "0";
        string result="";
        stack<char> stk;
        for (char c: num) {
            while(k>0 && !stk.empty() && stk.top()>c){
                stk.pop();
                k--;
            }
            stk.push(c);
        }
        while(k>0  && !stk.empty()) {
            stk.pop();
            k--;
        }
        while(!stk.empty()){
            result +=stk.top();
            stk.pop();
        }
        int i=result.length()-1;
        while(i>=0 && result.at(i)=='0'){
            result.pop_back();
            i--;
        }
        reverse(result.begin(),result.end());
        if(result.empty()) return "0";
        return result;
    }
};

int main(){
    string s="1432219";
    int k=3;
    Solution obj;
    cout<<obj.removeKdigits(s,k)<<endl;
}