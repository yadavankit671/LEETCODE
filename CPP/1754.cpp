#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string str=""; 
        int i=0, j=0;
        /*
        Laudey pehle lexicographically increasing ka matlab samajh k aa fir
        coding karna.. Interview main pelayega warna..
        */
        while(i<word1.length() && j<word2.length()) {
            char a=word1[i];
            char b=word2[j];
            if(a<=b){
                str+=b;
                str+=a;
            }
            else {
                str+=a;
                str+=b;
            }
            i++;
            j++;
        }
        while(i<word1.length()) str+=word1[i++];
        while(j<word2.length()) str+=word2[j++];
        return str;
    }
};
int main(){
    string word1="cabaa";
    string word2="bcaaa";
    Solution obj;
    cout<<obj.largestMerge(word1,word2);
}