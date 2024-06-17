#include<bits/stdc++.h>
using namespace std;
/*           |       |      | |   
- Step 1: [5,3,4,4,7,3,6,11,8,5,11] becomes [5,4,4,7,6,11,11]
- Step 2: [5,4,4,7,6,11,11] becomes [5,4,7,11,11]
- Step 3: [5,4,7,11,11] becomes [5,7,11,11]
*/
struct itrStore{

};
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        //         val,count
        stack<pair<int,int>> buffer;
        buffer.push(make_pair(nums.at(nums.size()-1),0));
        cout<<buffer.top().first<<"\t"<<buffer.top().second<<endl;
        int ans=0;
        for(int i=nums.size()-2;i>=0;i--){
            int count=0;
            while(!buffer.empty() && nums[i]>buffer.top().first){
                count=max(count+1,buffer.top().second);
                buffer.pop();
            }
            ans=max(count,ans);
            buffer.push(make_pair(nums[i],count));
            cout<<buffer.top().first<<"\t"<<buffer.top().second<<endl;
        }
        return ans;
    }
    
};
int main(){
    Solution obj;
    vector<int> nums={7, 14, 4, 14, 13, 2, 6, 13, 7, 5, 3, 5};
    cout<<obj.totalSteps(nums);
}

/*
void print(stack<pair<int,int>> buffer){
        if(buffer.empty()){
            cout<<"Stack is empty !!"<<endl;
            return;
        }
        stack<pair<int,int>> temp=buffer;
        cout<<"Stack : ["<<temp.top().first;
        temp.pop();
        while(!temp.empty()){
            cout<<","<<temp.top().first;
            temp.pop();
        }
    }
    void print(vector<int> nums){
        if(nums.size()==0){
            cout<<"Empty Array"<<endl;
            return;
        }
        cout<<"\nList : {"<<nums[0];
        for(int i=1;i<nums.size();i++){
            cout<<","<<nums[i];
        }
        cout<<"}"<<endl;
    }
*/