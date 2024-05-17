#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words(26,"");
        int k=0;int i=0;
        for(; i<pattern.length() && k<s.length();i++){
            string word="";
            while(k<s.length()){
                if(s[k]==' ') break;
                else word+=s[k++];
            }
            k++;
            if(words[pattern[i]-'a']=="") words[pattern[i]-'a'].append(word);
            else if(words[pattern[i]-'a']!=word) return false;
        }
        if(k<s.length() || i<pattern.length()) return false;
        for(int i=0; i<words.size();i++){
            if(words[i]!="")
            if(find(words.begin()+i+1, words.end(), words[i])!=words.end()) return false;
        }
        return true;
    }
};
int main(){
    string s="dog cat cat dog";
    string pattern="abba";
    Solution obj;
    cout<<obj.wordPattern(pattern,s);
}