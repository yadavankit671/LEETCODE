#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> result){
    if(result.empty()){
        cout<<"Result is empty"<<endl;
        return;
    }
    for(auto x: result){
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<",";
        }
        cout<<endl;
    }
}
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int n=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            vector<int> temp;
            long first=nums[i];
            for(int j=i+1;j<nums.size();j++){
                int start=j+1;
                int end=n;
                long second=nums[j];
                while(start<end){
                    long third=nums[start];
                    long fourth=nums[end];
                    if(first+second+third+fourth==target){
                        //cout<<nums[i]<<"\t"<<nums[j]<<"\t"<<nums[start]<<"\t"<<nums[end]<<endl;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);
                        sort(temp.begin(), temp.end());
                        if(find(result.begin(),result.end(),temp)==result.end()) result.push_back(temp);
                        temp={};
                        start++;
                        end--;
                    }
                    else if(first+second+third+fourth<target)start++;
                    else end--;
                }
            }
        }
        return result;
    }
};
int main(){
    vector<int> nums={1,0,-1,0,-2,2};
    int target=0;
    Solution obj;
    vector<vector<int>> result=obj.fourSum(nums,target);
    print(result);
}