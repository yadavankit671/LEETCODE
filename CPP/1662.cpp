#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a="";
        string b="";
        for(auto x: word1) a+=x;
        for(auto x: word2) b+=x;
        return a==b;
    }
};
int main(){
    //word1 = ["ab", "c"], word2 = ["a", "bc"]
    vector<string> word1={"ab", "cc"};
    vector<string> word2={"a", "bc"};
    Solution obj;
    if(obj.arrayStringsAreEqual(word1, word2)) cout<<"True";
    else cout<<"False";
}