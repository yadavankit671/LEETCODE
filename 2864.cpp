#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string result="";
        int counter=0;
        for(auto x: s) if(x=='1') counter++;
        for (int i=0;i<s.length()-1;i++){
            if(counter-1>0) {result+='1';   counter--;}
            else result+='0';
        }
        result+='1';
        return result;
    }
};
int main(){

}