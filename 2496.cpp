#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maximum=INT_MIN;
        for(auto x: strs){
            int temp=0;
            for(int i=0;i<x.length();i++){
                if(!isdigit(x[i])){
                    temp=x.length();
                    break;
                }
                else {
                    temp=temp*10+x[i]-'0';
                }
            }
            maximum=max(maximum,temp);
        }
        return maximum;
    }
};
int main(){
    vector<string> strs={"1","01","001","0001"};
    Solution obj;
    cout<<obj.maximumValue(strs)<<endl;
}