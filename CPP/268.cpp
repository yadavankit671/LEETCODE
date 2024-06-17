#include<bits/stdc++.h>
using namespace std;
void print(vector<bool> res){
    if(res.empty()){
        cout<<"Empty vector"<<endl;
        return;
    }
    cout<<"List : "<<res.at(0);
    for(int i=1;i<res.size();i++){
        cout<<","<<res[i];
    }
    cout<<endl;
}
class Solution{
    public:
    int missingNumber(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int size=nums.size();
        int add=(size*(size+1))/2;
        return add-sum;
    }
};
int main(){
    vector<int> nums={9,6,4,2,3,5,7,0,1};
    Solution obj;
    cout<<obj.missingNumber(nums);
}