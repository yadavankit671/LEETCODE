#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int stack[10000];
    int pos=1;
    vector<string> generateParenthesis(int n) {
        if(n==1) return vector<string>(1,"()");
        vector<string> ans;
        string temp="";
        for(int i=0;i<n;i++){
            temp.push_back('(');
            temp.push_back(')');
        }
        do{
            if(isValid(temp))
            ans.push_back(temp);
        }while(prev_permutation(temp.begin(),temp.end()));
        return ans;
    }
    bool isValid(string s){
        if(s.length()==0){
            return true;
        }
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stack[pos++]=s[i];
            }
            else if(c==1+stack[pos-1] || c==2+stack[pos-1]){
                pos--;
            }
            else{
                return false;
            }
        }
        return (pos==1)?true:false;
    }
};
int main(){
    Solution s;
    vector<string> ans=s.generateParenthesis(3);
    for(int i=0;i<ans.size();i++){
        cout<<"\""<<ans[i]<<"\""<<endl;
    }
}