#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool check(vector<bool> letters,string s){
        for(int i=0;i<s.length();i++){
            if(!letters[s[i]-'a']) return false;
        }
        return true;
    }
    public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> buffer(26,false);
        for(auto x: allowed) buffer[x-'a']=true;
        int count=0;
        for(auto x:words){
            if(check(buffer,x)) count++;
        }
        return count;
    }
};
int main(){
    vector<string> words={"cc","acd","b","ba","bac","bad","ac","d"};
    string allowed="cad";
    Solution s;
    cout<<s.countConsistentStrings(allowed,words);
}