#include<bits/stdc++.h>
using namespace std;
void printres(vector<vector<int>> result){
    if(result.size()==0){
        printf("List is empty");
        return;
    }
    cout<<"List : [";
    for(int i=0;i<result.size();i++){
        cout<<"["<<result[i][0];
        for(int j=1;j<result.at(i).size();j++){
            cout<<","<<result[i][j];
        }
        cout<<"]";
    }
    cout<<"]\n";
}
class Solution {
    private:
    void swap(int *a, int *b){
        int temp = *a;
        *a=*b;
        *b=temp;
    }
    void permute(vector<vector<int>> &result,vector<int> &nums,int low,int high){
        if(low==high){
            result.push_back(nums);
            return;
        }
        for(int i=low;i<=high;i++){
            swap(&nums[low],&nums[i]);
            permute(result,nums,low+1,high);
            swap(&nums[low],&nums[i]);
        }
    }
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int size=nums.size()-1;
        permute(result,nums,0,size);
        return result;
    }
};
int main(){
    vector<int> nums={1,2,3};
    Solution s;
    printres(s.permute(nums));
}