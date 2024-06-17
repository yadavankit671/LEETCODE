#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int size=s.length(); 
        if(size<k) {
            reverse(s.begin(),s.end());
            return s;
        } 
        int i=0;
        for(;i<size;){
            if(i+k>size) break;
            reverse(s.begin()+i,s.begin()+i+k);
            i+=k+k;
        }
        if(i<size-1) reverse(s.begin()+i,s.end());
        return s;
    }
};
int main(){
    string s="abcdefghijklmnop";
    Solution obj;
    cout<<obj.reverseStr(s,2);

}