#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for(int i=0;i<words.size();i++) {
            if(words[i].find(x)<words[i].length())result.push_back(i);
        }
        return result;
    }
};
int main(){
    vector<string> words={"abc","bcd","aaaa","cbc"};
    Solution obj;
    vector<int>result=obj.findWordsContaining(words,'a');
    for(int i=0;i<result.size();i++) cout<<result[i]<<",";
}