#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void BackTracking(vector<int> & candidates,int target,int index,vector<vector<int> > & result,int CurrSum,vector<int> &temp){
        if(CurrSum>target) return;
        if(CurrSum==target){
            result.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(candidates[i]+CurrSum<=target){
                temp.push_back(candidates[i]);
                BackTracking(candidates,target,i,result,CurrSum+candidates[i],temp);
                temp.pop_back();
            }
        }
        return;
    }
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> temp;
        BackTracking(candidates,target,0,result,0,temp);
        return result;
    }
};
int main(){
    vector<int> candidates={2,3,5};
    int target=8;
    Solution obj;
    vector<vector<int> > result=obj.combinationSum(candidates,target);
    cout<<endl<<"Result : "<<endl;
    for(vector<int>  itr : result){
        for(int x : itr){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}