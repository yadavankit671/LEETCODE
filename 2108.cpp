#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool palindrome(string str){
        int start = 0;
        int end=str.length()-1;
        while(start<end){
            if(str[start]!=str[end]) return false;
            start++;
            end--;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(palindrome(words[i])) return words[i];
        }
        return "";
    }
};
int main(){

}