#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(int i=0;i<n.length();i++){
            if (n[i]-'0'>ans) ans=n[i]-'0';
            if (ans==9) return ans;
        }
        return ans;
    }
};
int main(){
    string str="32";
    Solution s;
    cout<<s.minPartitions(str);
}