#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size=0;
        if(s.length() == 0) return 0;
        bool flag = false;
        for(int i = s.length()-1; i >=0 ;i--){
            if(s[i]!=' '){
                size++;
                flag = true;
            }
            else if (flag==true){
                return size;
            }
        }
        return size;
    }
};
int main(){
    string s="day";
    Solution so;
    cout<<so.lengthOfLastWord(s)<<endl;
}
