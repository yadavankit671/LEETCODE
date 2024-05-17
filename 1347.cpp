#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);
        for(char c: s) freq[c-'a']++;
        for(char c: t) freq[c-'a']--;
        int ans=0;
        for(int i=0;i<26;i++){
            if(freq[i]>0)
            ans+=freq[i];
        }
        return ans;
    }
};
int main(){
    string s = "bab", t = "aba";
    Solution obj;
    cout<<obj.minSteps(s,t)<<endl;
}