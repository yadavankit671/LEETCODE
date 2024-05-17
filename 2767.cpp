#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int ans=0;
        if(s.length()==1) return (s.at(0)=='1')?1:-1;
        return (ans==0)?-1:ans;
        int i=s.length()-1;
        while(i>=0){

        }
    }
};
int main(){
    string s="1";
    Solution obj;
    cout<<obj.minimumBeautifulSubstrings(s)<<endl;
}