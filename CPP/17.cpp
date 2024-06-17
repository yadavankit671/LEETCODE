#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void permute(int index,int len,string temp,string digits,vector<string> dictonary,vector<string> &result){
        if (temp.length()==len){
            result.push_back(temp);
            return;
        }
        string letter=dictonary[digits[index]-'0'];
        for(int i=0;i<letter.length();i++){
            temp+=letter.at(i);
            permute(index+1,len,temp,digits,dictonary,result);
            temp.pop_back();
        }
    }
    public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> dictonary={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int len=digits.length();
        if(len==0) return result;
        permute(0,len,"",digits,dictonary,result);
        return result;
    }
};
int main(){
    vector<string> result;
    Solution obj;
    string digits="678999";
    result=obj.letterCombinations(digits);
    for(auto x: result) cout<<x<<",";

}