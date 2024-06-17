#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeGood(string s) {
        string res="";
        res+=s.at(0);
        for(int i=1;i<s.length();i++){
            if(!res.empty() && abs(s.at(i)-res.at(res.length()-1))==32) res.pop_back();
            else res.push_back(s.at(i));
        }
        return res;
    }
};
int main(){
    string s="leEeetcode";
    Solution obj;
    cout<<"Result : ";
    cout<<obj.makeGood(s);
}