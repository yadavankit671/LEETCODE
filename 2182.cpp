#include<bits/stdc++.h>
using namespace std;
class Solution {
    private: 
    int nextIndex(vector<int> & freq,int curr){
        for(int i=25;i>=0;i--){
            if(freq[i]>0 && i!=curr) return i;
        }
        return 0;
    }
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(auto x: s) freq[x-'a']++;
        string result="";
        int i=-1;
        while(result.length()<s.length()){
            i=nextIndex(freq,i);
            int j=repeatLimit;
            while(j>0 && freq[i]>0){
                result+=char(i+'a');
                freq[i]--;
                j--;
            }
        }
        return result;
    }
};
int main(){
    string s="cczazcc";
    Solution obj;
    int repeatLimit=3;
    cout<<obj.repeatLimitedString(s,repeatLimit);
}