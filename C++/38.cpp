#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    string solve(string str){
        string result="";
        pair<int,int> temp={-1,0};
        for(int i=0;i<str.length();i++){
            if(str[i]-'0' !=temp.first){
                if(temp.second>0){
                    result+=to_string(temp.second)+to_string(temp.first);
                }
                temp={str[i]-'0',1};
            }
            else temp.second++;
        }
        result+=to_string(temp.second)+to_string(temp.first);
        return result;
    }
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string result="1";
        for(int i=1;i<n;i++){
            result=solve(result);
        }        
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.countAndSay(13);
    return 0;
}