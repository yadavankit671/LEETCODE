#include<bits/stdc++.h>
#include<string.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0)
        return true;
        vector<char> temp;
        for(int i=0;i<s.length();i++){
            if (isalpha(s[i])>=1 || isdigit(s[i])>=1){
                temp.push_back(toupper(s[i]));
            }
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=temp[temp.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};
int main(){
    string str ="0P";
    Solution s;
    cout<<s.isPalindrome(str);
}