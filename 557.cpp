#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void reverse(int start,int end,string &s){
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
public:
    string reverseWords(string s) {
        int start=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                reverse(start,i-1,s);
                start=i+1;
            }
        }
        reverse(start,s.length()-1,s);
        return s;
    }
};
int main(){
    string rev="Let's take LeetCode contest";
    Solution obj;
    cout<< obj.reverseWords(rev);
}