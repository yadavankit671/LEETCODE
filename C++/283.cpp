#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1)return;
        int size = nums.size();
        int index=0;
        for(int i=0; i<size; i++){
            if(nums[i]!=0){
                nums[index]=nums[i];
                index++;
            }
        }
        for(int i=index;i<size;i++) nums[i]=0;
    }
};
int main(){

}