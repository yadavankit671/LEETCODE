#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> result){
    if(result.empty()){
        cout<<"List is Empty "<<endl;
        return;
    }
    for(auto x: result){
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
}
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> list;
        for(auto x: nums) 
            if(!list[x]) list[x] = 1;
            else list[x]++;
        vector<vector<int>> result;
        while(!list.empty()){
            vector<int> temp;
            for(auto x=list.begin();x!=list.end();){
                temp.push_back(x->first);
                x->second--;
                if(x->second==0){
                    int temp=x->first;
                    x++;
                    list.erase(temp);
                }
                else x++;
            }
            if(!temp.empty()) result.push_back(temp);
        }
        return result;
    }
};
int main(){
    vector<int> nums={1,3,4,1,2,3,1};
    Solution obj;
    print(obj.findMatrix(nums));
}