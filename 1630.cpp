#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool check(vector<int> nums,int start,int end){
        vector<int> subArray;
        for(int i=start;i<=end;i++){
            subArray.push_back(nums[i]);
        }
        sort(subArray.begin(),subArray.end());
        int diff=subArray.at(1)-subArray.at(0);
        for(int i=subArray.size()-1;i>0;i--){
            if(subArray[i]-diff!=subArray[i-1]) return false;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        for(int i=0;i<l.size();i++){
            result.push_back(check(nums,l[i],r[i]));
        }
        return result;
    }
};
int main(){
    vector<int> nums={-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
    vector<int> left={0,1,6,4,8,7};
    vector<int> right={4,4,9,7,9,10};
    Solution obj;
    vector<bool> result=obj.checkArithmeticSubarrays(nums,left,right);
    for(auto x: result) if(x==true) cout<<"True"<<","; else cout<<"False"<<",";
    // result={false,true,false,false,true,true}
}