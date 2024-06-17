#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result=0;
        int prev=0;
        for(int i=0;i<bank.size();i++){
            int sum=0; 
            for(auto x:bank[i]) if(x=='1')sum+=1;
            if(sum>0){
                result+=prev*sum;
                prev=sum;
            }
        }
        return result;
    }
};
int main(){
    vector<string> bank={"011001","000000","010100","001000"};
    Solution obj;
    cout<<obj.numberOfBeams(bank)<<endl;
}