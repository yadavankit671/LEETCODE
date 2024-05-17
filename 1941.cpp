#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int> list;
        for(auto x: s) list[x]++;
        int check=list.begin()->second;
        for(auto x: list) if(x.second!=check) return false;
        return true;
    }
};
int main(){
    string str="abaacbc";
    Solution obj;
    cout<<obj.areOccurrencesEqual(str)<<endl;
}