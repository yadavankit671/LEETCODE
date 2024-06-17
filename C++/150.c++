#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1) return stoi(tokens[0]);
        vector<int> buffer;
        for(auto itr=tokens.begin();itr<tokens.end();itr++){
            if(*itr=="+"){
                int x,y;
                x=buffer[buffer.size()-1];
                buffer.pop_back();
                y=buffer[buffer.size()-1];
                buffer.pop_back();
                buffer.push_back(x+y);
            }
            else if(*itr=="-"){
                int x,y;
                x=buffer[buffer.size()-1];
                buffer.pop_back();
                y=buffer[buffer.size()-1];
                buffer.pop_back();
                buffer.push_back(y-x);
            }
            else if(*itr=="*"){
                int x,y;
                x=buffer[buffer.size()-1];
                buffer.pop_back();
                y=buffer[buffer.size()-1];
                buffer.pop_back();
                buffer.push_back(x*y);
            }
            else if(*itr=="/"){
                int x,y;
                x=buffer[buffer.size()-1];
                buffer.pop_back();
                y=buffer[buffer.size()-1];
                buffer.pop_back();
                buffer.push_back(y/x);
            }
            else buffer.push_back(stoi(*itr));
        }
        return buffer[buffer.size()-1];
    }
};
int main(){
    vector<string> tokens={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    cout<<s.evalRPN(tokens);
}