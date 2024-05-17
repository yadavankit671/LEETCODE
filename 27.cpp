#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i=0;i<nums.size();){
            if(val ==nums.at(i)){
                nums.erase(nums.begin()+i,nums.begin()+i+1);
            }
            else i++;
        }
        return nums.size();
    }
};
int main(){

}