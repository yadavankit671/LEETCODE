#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        //         index rep
        vector<pair<int,int>> buffer(26,make_pair(0,0));
        for(int i=0; i<s.length(); i++){
            if(buffer[s[i]-'a'].first==0) buffer[s[i]-'a'].first=i;
            buffer[s[i]-'a'].second++;
        }
        int mini=INT_MAX;
        for(int i=0;i<buffer.size();i++){
            if(buffer[i].second==1){
                mini = min(mini,buffer[i].first);
            }
        }
        return (mini==INT_MAX)?-1:mini;
    }
};
int main(){

}