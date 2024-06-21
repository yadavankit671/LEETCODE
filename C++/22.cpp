#include<bits/stdc++.h>
using namespace std;
/*
This works but is slow and not efficient : permutation takes the time complexity to n*n!
In leetcode the input is upto 8 so it seems faster solution but logically is not.
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
*/
class Solution {
    private : 
    void BackTracking(vector<string> &result,int open, int close,string &curr,int n){
        if(curr.length()==2*n) {
            result.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            BackTracking(result,open+1,close,curr,n);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            BackTracking(result,open,close+1,curr,n);
            curr.pop_back();
        }
    }
    public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr="";
        BackTracking(result,0,0,curr,n);
        return result;
    }
};
int main(){
    Solution s;
    vector<string> ans=s.generateParenthesis(4);
    for(int i=0;i<ans.size();i++){
        cout<<"\""<<ans[i]<<"\""<<endl;
    }
}