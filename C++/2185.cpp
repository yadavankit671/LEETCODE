#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(int i = 0; i < words.size();i++){
            if(words.at(i).substr(0,pref.length())==pref) cnt++;
        }
        return cnt;
    }
};
int main(){
    vector<string> words={"pay","attention","practice","attend"};
    string pref="at";
    Solution obj;
    cout<<obj.prefixCount(words,pref);
}