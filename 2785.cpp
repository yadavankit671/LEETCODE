#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowel;
        vector<int> index;
        vector<char> v={'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<s.length();i++) {
            if(find(v.begin(), v.end(),s[i])!=v.end()){
                vowel.push_back(s[i]);
                index.push_back(i);
            }
        }
        sort(vowel.begin(),vowel.end(),[](char &a,char &b){ return a < b; });
        for(int i=0;i<vowel.size();i++){
            s.at(index.at(i))=vowel[i];
        }
        return s;
    }
};
int main(){// ans=lEOtcede
    string s="lEetcOde";
    Solution obj;
    cout<<obj.sortVowels(s)<<endl;
}