#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(false);
        sort(happiness.begin(),happiness.end(),[](int a,int b){return a>b;});
        k--;
        int j=0;
        int minus=1;
        long long ans=0;
        ans+=happiness.at(j++);
        while(j<happiness.size() && k>0){
            int sum=happiness.at(j)-minus;
            if(sum<=0) break;
            ans+=sum;
            minus++;
            j++;
            k--;
        }
        return ans;
    }
};
int main(){

}