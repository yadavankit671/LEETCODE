#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long countVowelStrings(int n) {
        vector<vector<int>> dp(n, vector<int>(5, 0));
        for(int i=0;i<dp.size();i++) dp[i][0]=1;
        for(int i=0;i<5;i++) dp[0][i] =1;
        /*
        Matrix initialized ...
        1           1            1          1           1       
        1    (i,j-1)+(i-1,j)
        1
        1
        1
        
        Final Matrix :
        1   1   1   1   1
        1   2   3   4   5
        1   3   6   10  15
        1   4   10  20  35
        1   5   15  35  70  ==> 70+35+15+5+1 = 126 --> answer
        */
        for(int i=1;i<n;i++){
            for(int j=1;j<5;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return accumulate(dp[n-1].begin(),dp[n-1].end(),0);
    }
};

int main() {
    Solution sol;
    int n = 473; // Example input (int limit 473)
    cout<<INT_MAX<<endl;
    cout << sol.countVowelStrings(n) << endl; // Output the result
    return 0;
}