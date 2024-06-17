#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        long sum1=0,sum2=0;
        int k=0;
        for(int i=0;i<t.length();i++){
            sum1+=t[i];
            if(k<s.length())
            sum2+=s[k++];
        }
        return char(sum1-sum2);
    }
};
int main(){
    string s="abcd";
    string t="abcde";
    Solution obj;
    cout<<obj.findTheDifference(s,t)<<endl;
}