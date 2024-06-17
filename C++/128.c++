#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        set<int> temp;
        for(int i=0;i<nums.size();i++){
            temp.insert(nums[i]);
        }
        int res=INT_MIN,count=1;
        int prev=*temp.begin();
        auto itr=temp.begin();
        for(itr++;itr!=temp.end();){
            if(*itr==prev+1){
                count++;
                prev=*itr;
                itr++;
            }
            //1->2->3->4->100->200
            else{
                res=max(count,res);
                count=1;
                prev=*itr;
                itr++;
            }
        }
        return max(res,count);
    }
    void print(set<int> temp){
        for(auto x:temp){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Solution s;
    vector<int> nums={0,3,7,2,5,8,4,6,0,1};
    cout<<s.longestConsecutive(nums);
}
