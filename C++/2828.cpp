#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        for(int i=words.size()-1;i>=0;i--){
            if(s.empty()) return false;
            if (words[i].at(0)==s.at(s.length()-1)){
                s.pop_back();
            }
            else return false;
        }
        return true;
    }
};
int main(){
    vector<string> words={"never","gonna","give","up","on","you"};
    string s="ngguoy";
    Solution obj;
    if(obj.isAcronym(words,s)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}