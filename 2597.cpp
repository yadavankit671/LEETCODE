#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool isPresent(const std::vector<int>& curr, int element) {
    int i=0;
    int j=curr.size()-1;
    while(i<=j) { 
        int mid=i+(j-i)/2; 
        if (curr[mid]==element) return true;
        else if (curr[mid]>element) j=mid-1;
        else i=mid+1;
    }
    return false; 
}
    void backTracking(vector<int> & nums,int k,int &result,int index,vector<int> &curr){
        if(index==nums.size())  return;
        if(curr.empty() || !isPresent(curr,nums[index])){
            curr.push_back(nums[index]+k);
            backTracking(nums,k,result,index+1,curr);
            result++;
            curr.pop_back();
        }
        backTracking(nums,k,result,index+1,curr);
    }
    public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int result=0;
        vector<int> curr;
        backTracking(nums,k,result,0,curr);
        return result;
    }
};
int main(){
    vector<int> arr={2,4,6};
    Solution obj;
    cout<<"Result :"<<obj.beautifulSubsets(arr,2)<<endl;
}
