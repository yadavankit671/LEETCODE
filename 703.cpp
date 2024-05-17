#include<bits/stdc++.h>
using namespace std;
class KthLargest {
    private:
    int k;
    priority_queue<int,vector<int>,greater<int>> q;
    void fill(vector<int> nums,int start,int end){
        for(int i=start;i<end;i++){
            q.push(nums[i]);
        }
    }
    public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        if(nums.size()>k) {
            fill(nums,0,k);
            for(int i=k;i<nums.size();i++){
                if( nums[i]>q.top()){
                    q.push(nums[i]);
                    q.pop();
                }
            }
        }
        else fill(nums,0,nums.size());
    }
    int add(int val) {
        if ( q.size()<k) q.push(val);
        else if(val>q.top()){
            q.push(val);
            q.pop(); 
        }
        return q.top();
    }
};

int main(){
    vector<int> nums={0};
    KthLargest k(2,nums);
    cout<<k.add(-1)<<endl;
    cout<<k.add(1)<<endl;
    cout<<k.add(-2)<<endl;
    cout<<k.add(-4)<<endl;
    cout<<k.add(3)<<endl;
}