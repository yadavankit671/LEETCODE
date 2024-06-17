#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures){
        int n = temperatures.size();
        stack<pair<int, int>> s;
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--){
            if (!s.empty()){
                while (!s.empty() && s.top().first <= temperatures[i]){
                    s.pop();
                }
            }
            res[i] = s.empty() ? 0 : s.top().second - i;
            s.push(make_pair(temperatures[i], i));
        }
        return res;
    }
    void print(vector<int> result){
        cout << "Result: ";
        for (int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    vector<int> temp = {99,99,99,99,99,99,99,99,99,99,99,99,99,100};
    Solution s;
    temp = s.dailyTemperatures(temp);
    s.print(temp);
}