#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void BackTracking(vector<int> & nums,vector<vector<int>> & result,int index,vector<int> &curr){
        result.push_back(curr);
        for(int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            BackTracking(nums,result,i+1,curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> temp;
        result.push_back(temp);
        BackTracking(nums,result,0,temp);
        return result;
    }
};
void print(vector<vector<int>>  result){
    if(result.empty()) return;
    for(vector<int> arr : result){
        if(arr.empty()) {
            cout<<"[]"<<endl;
            continue;
        }
        cout<<"["<<arr[0];
        for(int i=1;i<arr.size();i++){
            cout<<","<<arr[i];
        }
        cout<<"],";
    }
}
int main(){
    Solution obj;
    vector<int> nums={1,2,3};
    print(obj.subsets(nums));
}