#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()<=1) return;
        reverse(s.begin(), s.end());
    }
};
int main(){
    vector<char> s={'a','b','c','d','e','f'};
    Solution obj;
    obj.reverseString(s);
    return 0;
}