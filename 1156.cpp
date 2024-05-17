#include<bits/stdc++.h>
using namespace std;
class Solution {
    private: 
    void solve(vector<vector<int> > & buffer,int & result){
        int temp=INT_MIN;
        for(auto x: buffer){
            if(x.empty()) continue;
            int maxlen=0;
            for(int i=0;i<x.size()-1;i++){
                if(x[i]+1==x[i+1]) maxlen+=1;
                else if(i+2<x.size() && x[i]+2==x[i+1]) maxlen+=1;
                else {
                    temp=max(temp,maxlen);
                    maxlen=1;
                }
            }
            if(maxlen!=x.size()) result=max(result,temp);
        }
    }
public:
    int maxRepOpt1(string text) {
        int result=-1;
        vector<vector<int> > buffer(26);
        for(int i=0;i<text.length();i++){
            buffer[text[i]-'a'].push_back(i);
        }
        solve(buffer,result);
        return result;
    }
};
int main(){
    string text="aaabaaa";
    Solution obj;
    cout<<obj.maxRepOpt1(text)<<endl;
}