#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        for(;i<word.length();i++){
            if(word[i]==ch){
                reverse(word.begin(),word.begin()+i+1);
                break;
            }
        }
        return word;
    }
};
int main(){
    string word="abcdefd";
    char ch='d';
    Solution obj;
    cout<<obj.reversePrefix(word,ch)<<endl;
}