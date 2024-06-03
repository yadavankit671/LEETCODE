#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void setBits(int num,vector<int> &bitarray){
        for(int i=0;i<32;i++){
            bitarray[i]+=num&1;
            num=num>>1;
        }
    }
    public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitarray(32,0);
        for( int x : nums) setBits(x,bitarray);
        bitset<32> number;
        for(int i=0;i<32;i++){
            if(bitarray[i]%3!=0) number.set(i);
        }
        return number.to_ulong();
    }
};
int main(){
    Solution s;
    vector<int> nums={7,4,7,7,3,3,3};
    cout<<s.singleNumber(nums);
    return 0;
}