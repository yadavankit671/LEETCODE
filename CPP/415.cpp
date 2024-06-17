#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry=0;
        int k=num2.length()-1;
        int j=num1.length()-1;
        string result="";
        while(j>=0 || k>=0 || carry!=0) {
            int sum=((j>=0)?(num1[j--]-'0'):0)+((k>=0)?(num2[k--]-'0'):0)+carry;
            result=char((sum%10)+'0') +result;
            carry=sum/10;
        }
        return result;
    }
};
int main(){
    string num1="11";
    string num2="123";
    Solution obj;
    cout<<obj.addStrings(num1,num2)<<endl;
}