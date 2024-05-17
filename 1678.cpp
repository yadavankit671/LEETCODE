#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string interpret(string command) {
        string result="";
        for(int i=0;i<command.length()-1;i++){
            if(command[i]=='(' && command[i+1]==')'){
                result+="o";
                i++;
            }
            else if(command[i]=='(' && command[i+1]=='a'){
                result+="al";
                //(al)
                i+=3;
            }
            else result+="G";
        }
        if(command.at(command.length()-1)=='G') result+="G";
        return result;
    }
};
int main(){
    string command="(al)G(al)()()G";
    Solution obj;
    cout<<obj.interpret(command);
}