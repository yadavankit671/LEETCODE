#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int counter=0;
        for(int i=0;i<details.size();i++){
            int temp=details[i].at(11)-'0';
            temp*=10;
            temp+=details[i].at(12)-'0';
            if(temp>60) counter++;
        }
        return counter;
    }
};
int main(){
    vector<string> details={"7868190130M7522","5303914400F9211","9273338290F4010"};
    Solution obj;
    cout<<obj.countSeniors(details);
}