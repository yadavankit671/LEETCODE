#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int counter=0;
        map<string,int> buffer;
        for(int i=0;i<words.size();i++){
            string word=words[i];
            string rev=word;
            reverse(rev.begin(),rev.end());
            if(buffer[word]==1){
                buffer[word]++;
            }
            else if(buffer[rev]==1) buffer[rev]++;
            else buffer[word]=1;
        }
        for (auto x: buffer) if(x.second==2)   counter++;
        return counter;
    }
};
int main(){
    vector<string> words={"cd","ac","dc","ca","zz","zz"};
    Solution obj;
    cout<<obj.maximumNumberOfStringPairs(words);
}