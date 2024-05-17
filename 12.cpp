#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string result;
        int ones=num%10;num/=10;
        int tens=num%10;num/=10;
        int hundreds=num%10;num/=10;
        int thousands=num%10;num/=10;
        vector<string> one={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string> ten={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> hun={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> thousand={"","M","MM","MMM"};
        result+=thousand[thousands];
        result+=hun[hundreds];
        result+=ten[tens];
        result+=one[ones];
        return result;
    }
};
int main(){
    int n=333;
    Solution obj;
    cout<<obj.intToRoman(n);
}