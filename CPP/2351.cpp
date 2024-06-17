#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int> repeat;
        char res;
        for(auto x: s){
            if (repeat[x]+1==2) {res=x; break;}
            else repeat[x] =1;
        }
        return res;
    }
};
int main(){
    string str="abccbaacz";
    Solution obj;
    cout<<obj.repeatedCharacter(str);
}