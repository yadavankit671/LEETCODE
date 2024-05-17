#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        vector<bool> vowels(26,false);
        vowels['a'-'a']=true;
        vowels['e'-'a']=true;
        vowels['i'-'a']=true;
        vowels['o'-'a']=true;
        vowels['u'-'a']=true;
        int result = 0;
        int size=min<int>(right,words.size()-1);
        int i=0;
        while(i<=size){
            char x=words.at(i).at(0);
            char y=words.at(i).at(words.at(i).length()-1);
            if(vowels[x-'a'] && vowels[y-'a']) result++;
        }
        return result;
    }
};
int main(){

}