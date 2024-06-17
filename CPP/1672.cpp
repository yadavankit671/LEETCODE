#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result=INT_MIN;
        for(auto x: accounts){
            result=max(result,accumulate(x.begin(),x.end(),0));
        }
        return result;
    }
};
int main(){
    vector<vector<int>> accounts={{2,8,7},{7,1,3},{1,9,5}};
    Solution obj;
    cout<<obj.maximumWealth(accounts)<<endl;
}