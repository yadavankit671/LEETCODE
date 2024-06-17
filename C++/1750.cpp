#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(0);
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                int temp=i;
                int temp2=j;
                while(s[temp]==s[j] && temp<j) temp++;
                while(s[i]==s[temp2] && temp2>i) temp2--;
                i=temp;
                j=temp2;
            }
            else break;
        }
        int count=j-i+1;
        return (count<0)?0:count;
    }
};
int main(){
    string s="aabccabba";
    Solution obj;
    cout<<"\nAns : "<<obj.minimumLength(s);
}