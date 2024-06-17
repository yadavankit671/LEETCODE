#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<bool> > dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print(vector<vector<string> > &result){
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
class Solution {
    private:
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result, const vector<vector<bool>>& dp) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }
        for (int end = start; end < s.length(); ++end) {
            if (dp[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, path, result, dp);
                path.pop_back();
            }
        }
    }
    public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                if (s[i] == s[j] && (length == 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        print(dp);
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result, dp);
        return result;
    }


};
int main(){
    Solution s;
    vector<vector<string>> result = s.partition("aabbccaaba");
    print(result);
    return 0;
}