#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> list(s.length());
        for(int i=0;i<s.length();i++){
            list[indices[i]]=s[i];
        }
        string res="";
        for(int i=0;i<list.size();i++){
            res+=list[i];
        }
        return res;
    }
};
int main(){
    vector<int> indices={4,5,6,7,0,2,1,3};
    string str="codeleet";
    Solution obj;
    cout<<obj.restoreString(str,indices);
}