#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        using int_char=pair<int,char>;
        int len=s.length();
        string result="";
        if(len==0)return result;
        vector<pair<int,string>> characters(256,make_pair(0,""));
        for(int i=0;i<len;i++){
            characters[s[i]].first++;
            characters[s[i]].second+=s[i];
        }
        sort(characters.begin(), characters.end(),[](pair<int,string> a,pair<int,string>b){return a.first>b.first;});
        for(int i=0;i<characters.size();i++){if (characters[i].first>0)result+=characters[i].second;}
        return result;
    }
};
int main(){
    string s="Aabb";
    Solution obj;
    cout<<endl<<obj.frequencySort(s);
}