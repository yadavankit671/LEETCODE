#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void solve(vector<vector<int>> &result,vector<int> &nums,vector<int> temp,int start){
        if(start>=nums.size()){
            if(temp.size()>=2) result.push_back(temp);
            return; 
        }
        if(temp.empty() || nums[start]>=temp.at(temp.size()-1)){
            temp.push_back(nums.at(start));
            solve(result,nums,temp,start+1);
            temp.pop_back();
        }
        if(temp.size()==0 || nums.at(start)!=temp.back())
        solve(result,nums,temp,start+1);
        // for(int i=start;i<nums.size();i++){
        //     if(temp.empty() || temp.at(temp.size()-1)<=nums.at(i)) temp.push_back(nums.at(i));
        //     solve(buff,nums,temp,i+1);
        //     temp.pop_back();
        //     if(temp.size()>=2 )
        //     buff.insert(temp);
        // }
    }
    void print(vector<vector<int>> result){
        if(result.empty()){
            cout<<"\nEmpty Vectors!"<<endl;
            return;
        }
        cout<<"\nResult :";
        for(auto x: result){
            for(int i =0;i<x.size();i++){
                cout<<x.at(i)<<",";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(result,nums,temp,0);
        return result;
    }
};
int main(){
    vector<int> nums={4,4,3,2,1};
    Solution obj;
    vector<vector<int>> result=obj.findSubsequences(nums);
    cout<<"Final : "<<endl;
    for(auto x: result){
        for(int i=0;i<x.size();i++){
            cout<<x.at(i)<<",";
        }
        cout<<endl;
    }
}