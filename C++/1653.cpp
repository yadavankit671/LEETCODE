#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        int result = 0;
        int count = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == 'b') count++;
            else if(count > 0) {
                result ++;
                count --;
            }
        }
        return result;
    }
};
int main(){
    string s = "baababbaabbaaabaabbabbbabaaaaaabaabababaaababbb";
    Solution obj;
    cout<<obj.minimumDeletions(s)<<endl;
    return 0;
}