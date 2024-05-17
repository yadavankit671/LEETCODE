#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bits_calc(string s){
        int ans = 0;
        for(int i = 0; i <s.length(); i++){
            if(s[i] == '1') ans++;
        }
        return ans;
    }
    int hammingWeight(uint32_t n) {
        string s;
        while(n>0){
            s+=to_string(n%2);
            n/=2;
        }
        return bits_calc(s);
    }
};
int main(){
    uint32_t n=4294967293;
    Solution obj;
    cout<<obj.hammingWeight(n);
}