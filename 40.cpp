#include<bits/stdc++.h>
using namespace std;
class Solution {
    private: 
    void BackTracking (vector<int> &candidates,int index,int target,vector<vector<int> > & result,vector<int> temp,int currSum){
        if(currSum==target) {
            result.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(currSum+candidates[i]>target) break;
            if(i>index && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            BackTracking(candidates,i+1,target,result,temp,currSum+candidates[i]);
            temp.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        BackTracking(candidates,0,target,result,temp,0);
        return result;
    }
};
//candidates = [10,1,2,7,6,1,5], target = 8
int main(){
    vector<int> candidates={10,1,2,7,6,1,5};
    int target=8;
    Solution obj;
    vector<vector<int> > result=obj.combinationSum2(candidates,target);
    cout<<endl;
    for(vector<int> arr : result){
        for(int x : arr) cout<<x<<",";
        cout<<endl;
    }
}