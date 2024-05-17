#include<bits/stdc++.h>
using namespace std;
void print(unordered_map<int,int> list ){
    if(list.empty()){
        cout<<"Empty List !!"<<endl;
        return;
    }
    cout<<"\nList :\n";
    for(auto itr: list) cout<<itr.first<<"\t"<<itr.second<<endl;
}
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<pair<int,int>> nums;
        nums.push_back(make_pair(arr[0],1));
        for(int i=1;i<arr.size();i++){
            if(arr[i]==nums[nums.size()-1].first) nums[nums.size()-1].second++;
            else nums.push_back(make_pair(arr[i],1));
        }
        sort(nums.begin(), nums.end(),[](pair<int,int> a,pair<int,int> b){return a.second>b.second;});
        for(auto x: nums) cout<<x.first<<"\t"<<x.second<<endl;
        for(auto x=nums.rbegin();x!=nums.rend();){
            if(x->second<k){
                k-=x->second;
                x++;
                nums.pop_back();
            }
            else if(x->second==k){
                nums.pop_back();
                break;
            }
            else{
                break;
            }
        }
        return nums.size();
    }
};
int main(){
    vector<int> arr={2,4,1,8,3,5,1,3};
    Solution obj;
    int k=3;
    cout<<obj.findLeastNumOfUniqueInts(arr,k);
}