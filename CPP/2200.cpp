#include<bits/stdc++.h>
using namespace std;
void print(vector<int> result){
    if(result.empty()){
        cout<<"Empty Result"<<endl;
        return;
    }
    cout<<"Result : ["<<result.at(0);
    for(int i=1;i<result.size();i++){
        cout<<","<<result.at(i);
    }
    cout<<"]"<<endl;
}
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> indices;
        for(int i=0;i<nums.size();i++){
            if(nums.at(i)==key) indices.insert(i);
        }
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            auto itr=indices.rbegin();
            while(itr!=indices.rend()){
                if(abs(i-*itr)<=k) {
                    result.push_back(i);
                    break;
                }
                itr++;
            }
        }
        return result;
    }
};
int main(){
    vector<int> nums={3,4,9,1,3,9,5};
    int key=9;
    int k=1;
    Solution obj;
    vector<int> result=obj.findKDistantIndices(nums,key,k);
    print(result);
}