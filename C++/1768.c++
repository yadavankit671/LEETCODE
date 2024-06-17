#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if(word1.length()==0) return word2;
        if(word2.length()==0) return word1;
        string res;int k=0;
        for(int i=0;;i++){
            if(i>=word1.length() && i>=word2.length()) break;
            if(i<word1.length()) res.push_back(word1[i]);
            if(i<word2.length()) res.push_back(word2[i]);
        }
        return res;
    }
};
int main(){

}