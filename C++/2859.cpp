#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool binary(int temp,int k){
        int counter=0;
        while(temp>0){
            if(temp%2==1) counter++;
            temp/=2;
        }
        return counter==k;
    }
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int size = nums.size()-1;
        int res=0;
        while(size>=0){
            if(binary(size,k)) res+=nums[size];
            size--;
        }
        return res;
    }
};
int main(){
    vector<int> nums={5,10,1,5,2};
    Solution obj;
    cout<<obj.sumIndicesWithKSetBits(nums,1);
}