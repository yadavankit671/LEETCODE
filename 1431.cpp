#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maximum=INT_MIN;
        for(auto x:candies) if(x>maximum) maximum=x;
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maximum) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};
int main(){
    vector<int> candies={2,3,5,1,3};
    int extraCandies=3;
    Solution obj;
    vector<bool> result=obj.kidsWithCandies(candies,extraCandies);
    for(auto x: result) cout<<x<<",";
}