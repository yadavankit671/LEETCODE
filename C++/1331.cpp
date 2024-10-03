#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v(arr.begin(),arr.end());
        sort(v.begin(),v.end());
        int rank = 1;
        unordered_map<int, int > mp;
        for(int i = 0; i < v.size(); i++){
            mp[v[i]] = rank;
            if( i + 1 < v.size() && v[i] != v[i + 1]) rank++;
        }
        vector<int> res;
        for(int i = 0; i < arr.size(); i++){
            res.push_back(mp[arr[i]]);
        }
        return res;
    }
};
int main(){
    vector<int> arr = {40,10,20,30};
    Solution s;
    vector<int> res = s.arrayRankTransform(arr);
    for(int x : res) cout<<x<<" ";
}