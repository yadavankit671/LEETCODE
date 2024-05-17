#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        int start=0;
        int end=s.length()-1;
        vector<char> vowels(256,0);
        vowels['a']=1;
        vowels['e']=1;
        vowels['i']=1;
        vowels['o']=1;
        vowels['u']=1;
        vowels['A']=1;
        vowels['E']=1;
        vowels['I']=1;
        vowels['O']=1;
        vowels['U']=1;
        while(start<end){
            if(vowels[s[start]]!=1) start++;
            else if(vowels[s[end]]!=1) end--;
            else {
                swap(s[start],s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};
int main(){
    Solution obj;
    string s="aA";
    cout<<obj.reverseVowels(s);
}