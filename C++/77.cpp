#include<bits/stdc++.h>
using namespace std;
class Solution {
    private : 
    void BackTracking(int start, int end, int k, vector<vector<int> > &result,vector<int> &temp){
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
        for(int i=start;i<=end;i++){
            temp.push_back(i);
            BackTracking(i+1,end,k,result,temp);
            temp.pop_back();
        }
    }
    public :
    vector<vector<int> > combine(int n, int k){
        vector<vector<int> > ans;
        vector<int> temp;
        BackTracking(1,n,k,ans,temp);
        return ans;
    }
};
int main(){
    Solution obj;
    int n=10;
    int k=3;
    vector<vector<int> > result= obj.combine(n,k);
    for(vector<int> array : result){
        cout<<toString_custom(array)<<endl;
    }
}