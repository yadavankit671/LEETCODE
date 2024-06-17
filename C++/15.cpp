#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> result){
    if(result.size()==0) {
        cout<<"List is empty";
        return;
    }
    for(int i=0; i<result.size();i++){
        if(result[i].size()==0) cout<<"empty"<<endl;
        for(int j=0; j<result[i].size();j++){
            cout<<result[i][j]<<",";
        }
        cout<<endl;
    }
}
// instead of using binary search what we can do is use map and suppose that nums[start] is an answer and check rem=0-(first+nums[start])
// we increase start till 2nd last element . while pushing the vector we check that if it already exists in the resultant vector
            
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> buffer;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int first = i;
            int start=i+1;
            int end=nums.size()-1;
            vector<int> temp;
            while(start<end){
                if(nums[first]+nums[start]+nums[end]==0 && first!=start!=end){
                    temp.push_back(nums[first]);
                    temp.push_back(nums[end]);
                    temp.push_back(nums[start]);
                    sort(temp.begin(), temp.end());
                    buffer.insert(temp);
                    temp={};
                    start++;
                    end--;
                }
                else if(nums[first]+nums[start]+nums[end]<=0) start++;
                else end--;
            }
        }
        vector<vector<int>> result;
        for(auto x: buffer) result.push_back(x);
        return result;
    }
};
int main(){   // ans ==> [[-1,0,2],[-2,1,1]]
    vector<int> nums={1,2,-2,-1};
    Solution obj;
    print(obj.threeSum(nums));
}