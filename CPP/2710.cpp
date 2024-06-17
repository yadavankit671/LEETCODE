#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeTrailingZeros(string num) {
        for(int i=num.length()-1;num[i]=='0';i--){
            num.pop_back();
        }
        return num;
    }
};
int main(){
    string str="51230100";
    Solution obj;
    cout<<obj.removeTrailingZeros(str);
}