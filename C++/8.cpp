#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        if (s.length()==0){
            return 0;
        }
        vector<int>v;
        vector<char> operators;
        for(int i=0;i<s.length() && isalpha(s[i])==false;i++){
            if (s[i]=='.' || (v.size()>0 && !isdigit(s[i])))
            break;
            if (operators.size()>=1 && !isdigit(s[i]))
            return 0;
            if (s[i]=='-' || s[i]=='+'){
                operators.push_back(s[i]);
                if (operators.size()>1 || v.size()>0){
                    return 0;
                }
            }
            else if (isdigit(s[i])){
                v.push_back(s[i]-48);
            }
            
        }
        double result=0;
        for(int i=0;i<v.size();i++){
            result=result*10+v.at(i);
        }
        for(int i=0;i<operators.size();i++){
            if(operators[i]=='-' && result>=0){
                result=result*-1;
            }
            else if( result<0){
                return 0;
            } 
        }
        if (result<INT_MIN)
        result=INT_MIN;
        else if (result>=INT_MAX)
        result=INT_MAX;
        return result;
    }
};
int main(){
    string s1="+1",s2="   -42",s3="-4193 with words";
    Solution s;
    cout<<s.myAtoi(s1); //
}