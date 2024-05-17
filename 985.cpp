#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        nums.at(queries.at(0).at(1))+=queries.at(0).at(0);
        int sum=0;
        //dry run to get initial value of evenSum
        for(auto x: nums)
            if(x%2==0) 
                sum+=x;
        result.push_back(sum); // since we get the initial evenSum we start from 1 index in queries array
        for (int i=1;i<queries.size();i++){
            // changes will be made to the last value in the result vector
            sum=result.at(result.size()-1);
            int val=queries.at(i).at(0);
            int index=queries.at(i).at(1);
            if(nums.at(index)%2==0){
                if((nums.at(index)+val)%2==0){
                    sum+=val;
                }
                else {
                    sum-=nums.at(index);
                }
            }
            else {
                if((nums.at(index)+val)%2==0){
                    sum+=nums.at(index)+val;
                }
            }
            nums.at(index)+=val;
            result.push_back(sum);
        }
        return result;
    }
};
int main(){
    vector<int> nums={1,2,3,4};
    vector<vector<int>> queries={{1,0},{-2,1},{-4,0},{2,3}};
    Solution obj;
    vector<int> result=obj.sumEvenAfterQueries(nums,queries);
    for(auto x: result) cout<<x<<",";
}