#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        int index = nums2.size()-1;
        while(index>=0){
            int currElement = nums2[index--];
            while(!st.empty() && st.top()<=currElement) st.pop();
            mp[currElement] = st.empty() ? -1 : st.top();
            st.push(currElement);
        }
        for(int i=0;i<nums1.size();i++) nums1[i]=mp[nums1[i]];
        return nums1;
    }
};
int main(){
    Solution obj ;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int>  result = obj.nextGreaterElement(nums1, nums2);
    for(int x : result ) cout<<x <<" ";
}