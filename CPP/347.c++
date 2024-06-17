#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len=nums.size();
        if(len==1) return nums;
        vector<pair<int,int>> temp;
        int prev=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++){
            if(nums[i]!=prev){
                temp.push_back(make_pair(1,nums[i]));
                prev=nums[i];
            }
            else{
                temp[temp.size()-1].first++;
            }
        }
        sort(temp.rbegin(), temp.rend());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp.at(i).second);
        }
        return ans;
    }
    void print(vector<pair<int,int>> temp){
        for(int i=0;i<temp.size();i++){
            cout<<temp[i].first<<" "<<temp[i].second<<endl;
        }
    }
    void print(vector<int>& ans) {
        cout<<"List : ";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,1,1,2,2,3};
    vector<int> ans=s.topKFrequent(nums,2);
    s.print(ans);
}