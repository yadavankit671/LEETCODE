#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
            vector<int> index(names.size());
            for(int i=0;i<heights.size();i++) index[i] =i;
            sort(index.begin(), index.end(),[&](int i,int j){return heights[i]>heights[j];});
            vector<string> res;
            for(int i=0;i<names.size();i++) res.push_back(names[index[i]]);
            return res;
    }
};
int main(){
    vector<int> heights={180,165,170};
    vector<string> names={"Mary","John","Emma"}; 
    Solution obj;
    names=obj.sortPeople(names,heights);
    for(auto x: names) cout<<x<<endl;
}