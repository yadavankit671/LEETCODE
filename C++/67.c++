#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string addBinary(string a,string b){
        int i=0,carry=0;
        string result="";
        while(i<a.length() || i<b.length() || carry!=0){
            int x=0,y=0;
            if (i<a.length() && a[a.length()-i-1]=='1') x=1;
            if (i<b.length() && b[b.length()-i-1]=='1') y=1;
            result=(((x+y+carry)%2==0)?"0":"1")+result;
            carry=(x+y+carry)/2;
            i++;
        }
        return result;
    }
};
int main(){
    Solution s;
    string a="10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101",
    b="110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    cout<<"resutl is "<<s.addBinary(a,b);
}
