#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string truncateSentence(string s, int k) {
        int space_counter=0;
        string result="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') space_counter++;
            if(space_counter>=k-1) break;
            result+=s[i];
        }
        return result;
    }
};
int main(){

}