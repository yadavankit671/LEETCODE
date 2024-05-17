#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        int result=0;
        while(num>0){
            result+=num%10;
            num/=10;
        }
        if (result>9){
            result = addDigits(result);
        }
        return result;
    }
};
int main(){
    Solution obj;
    cout<<obj.addDigits(38);
}