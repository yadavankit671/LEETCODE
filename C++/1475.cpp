#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int index = prices.size() - 1;
        while (index >= 0){
            int curr = prices.at(index);
            while(!st.empty() && st.top()>curr) st.pop();
            prices.at(index--) -= st.empty() ? 0 : st.top();
            st.push(curr);
        }
        return prices;
    }
};
