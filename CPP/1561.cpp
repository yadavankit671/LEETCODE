#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // 1,2,3,4,5,6,7,8,9
        sort(piles.begin(),piles.end());
        int result=0;
        int x=piles.size()/3;
        for(int i=piles.size()-2;i>=x;i-=2)  result+=piles[i];
        return result;
    }
};
int main(){
    vector<int> piles={9,8,7,6,5,4,3,2,1};
    Solution obj;
    cout<<obj.maxCoins(piles)<<endl;
}