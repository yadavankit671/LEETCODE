#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<pair<int,int>> buffer(256,make_pair(0,0));
        for(int i=0;i<s.size();i++){
            buffer[s[i]].first++;
            buffer[t[i]].second++;
        }
        for(int i=0;i<buffer.size();i++) if(buffer[i].first!=buffer[i].second) return false;
        return true;
    }
};
int main(){

}