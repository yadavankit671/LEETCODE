#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int result = 0;
        int size = height.size();
        for(int i = 0; i < size; i++){
            while(!st.empty() && height[st.top()] < height[i]){
                int curr = st.top();
                st.pop();
                if(st.empty()) break;
                int diff = i - st.top() - 1;
                result += (min(height[st.top()], height[i]) - height[curr]) * diff;
            }
            st.push(i);
        }
        return result;
    }
};
int main(){

}