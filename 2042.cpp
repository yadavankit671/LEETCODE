#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areNumbersAscending(string s) {
        int crnt=INT_MIN;
        for(int i=0;i<s.length();i++) {
            if(isdigit(s[i])){
                int temp=0;
                while(i!=s.length() && s[i]!=' '){
                    temp=temp*10+(s[i]-'0');
                    i++;
                }
                if(temp<=crnt) return false;
                
            }
        }
        return true;
    }
};
int main(){
    string str="1 box has 3 blue 4 red 6 green and 12 yellow marbles";
    Solution obj;
    if(obj.areNumbersAscending(str)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}