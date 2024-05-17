#include<bits/stdc++.h>
using namespace std;
void print(vector<int> nums){
    if(!nums.size()){
        cout<<"List is Empty "<<endl;
        return;

    }
    cout<<"List : "<< nums.at(0);
    for( int i=1;i<nums.size();i++) cout<<","<<nums.at(i);
    cout<<endl;
}
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2){
            swap(nums[i],nums[i-1]);
        }
        return nums;
    }
};
int main(){
    vector<int> nums={5,4,3,2,1,6};
    Solution obj;
    vector<int> result=obj.numberGame(nums);
    print(result);
}