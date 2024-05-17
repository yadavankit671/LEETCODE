#include<bits/stdc++.h>
using namespace std;
void print(vector<int> result){
    if(result.empty()) {
        cout<<"List is empty!"<<endl;
        return;
    }
    cout<<"List : "<<result.at(0);
    for(int i=1;i<result.size();i++){
        cout<<","<<result[i];
    }
    cout<<endl;
}
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for(int i=1;i<nums.size();i+=2){
            int freq=nums[i-1];
            while(freq){
                result.push_back(nums[i]);
                freq--;
            }
        }
        return result;
    }
};
int main(){
    vector<int> nums={1,2,3,4};
    Solution obj;
    vector<int> result=obj.decompressRLElist(nums);
    print(result);
}