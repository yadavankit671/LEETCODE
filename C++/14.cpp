#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length=0,count=0;
        int size =strs.size();
        while (strs[0][length]){
            length++;
        }
        bool flag=true;
        string res;
        for(int i=0;i<length && flag !=false;i++){
            for (int j=0;j<size-1;j++){
                if (strs[j][i]!=strs[j+1][i]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                res.push_back(strs[0][i]);
            }
        }
        return res;
    }
};
int main(){
    vector <string> strs;
    strs={"flower","flower","flow"};
    Solution s;
    cout<<s.longestCommonPrefix(strs);
}
