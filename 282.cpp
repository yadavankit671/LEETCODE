#include<bits/stdc++.h>
using namespace std;
class Solution {
    private: 
    void solve(string num,int target,int index,string curr,int step,vector<string> & result,char op){
        if(index>num.length()) return;
        if(step == target ){
            result.push_back(curr);
            return;
        }
        // multiplication is tricky 
        // 2 + 4 * 5  --> step = 2+4=6 then 4*5 ..doesn't work
        // if i step back .. 6-4 then 4*5.. doesn't work 
        // if 2*4*5 .. how to know what happened earlier...
        if(op=='+'){

        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        solve(num,target,0,"",0,result,'+');
        solve(num,target,2,"",0,result,'-');
        solve(num,target,1,"",0,result,'*');
        return result;
    }
};
int main(){

}