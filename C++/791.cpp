#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> alpha(26,0);
        for(int i=0;i<s.length();i++){
            alpha[s[i]-'a']++;
        }
        vector<char> ord;
        for(auto x:order) ord.push_back(x);
        string result="";
        for(int i=0;i<ord.size();i++){
            int len=alpha[ord[i]-'a'];
            while(len>0){
                result+=ord[i];
                len--;
            }
            alpha[ord[i]-'a']=0;
        }
        for(int i=0;i<alpha.size();i++){
            if(alpha[i]>0){
                int len=alpha[i];
                while(len>0){
                    result+=char(i+'a');
                    len--;
                }
                
            }
        }
        return result;
    }
};
int main(){
    string s="utzoampdgkalexslxoqfkdjoczajxtuhqyxvlfatmptqdsochtdzgypsfkgqwbgqbcamdqnqztaqhqanirikahtmalzqjjxtqfnh";
    string order="hucw";
    Solution obj;
    string result=obj.customSortString(order,s);
    cout<<result;
}