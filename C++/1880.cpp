#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int first=0,second=0,final=0;
        for(auto x: firstWord) first=first*10+(x-'a');
        for(auto x: secondWord) second=second*10+(x-'a');
        for(auto x: targetWord) final=final*10+(x-'a');
        return (first+second)==final;
    }
};
int main(){
    string firstword="acb";
    string secondword="cba";
    string targetword="cdb";
    Solution obj;
    if(obj.isSumEqual(firstword, secondword, targetword))cout<<"True";
    else cout<<"False";
}