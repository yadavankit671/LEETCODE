#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int one_count=0;
        for(auto x: nums) if(x==1) one_count++;
        int zero_count=nums.size()-one_count;
        if(goal==0){
            
        }
    }
};
int main(){

}
/*
[0, 0, 0, 0, 0]
0
[1, 1, 1, 1, 1]
3
[0, 1, 0, 1, 0]
2
[1, 0, 1, 0, 1]
3
[1, 0, 0, 1]
2
[0, 1, 0, 0]
1
[1, 1, 1, 0]
3
[0, 0, 0]
0
[1, 1, 0]
2
[1, 1, 0, 0, 0, 1, 1]
4
[0, 1, 1, 0, 1, 0, 0]
3
[1, 1, 1, 1, 1, 1, 1]
4
[0, 0, 0, 1, 1, 1]
3
[1, 0, 1, 0]
2
[0, 0, 1, 0, 0]
1
[1, 1, 0, 1, 0, 1, 0]
4
[1, 1, 1, 0, 0, 1, 1, 0]
5
[0, 1, 0, 1, 0, 1, 0, 1, 0]
4
[1, 0, 1, 1, 0, 1, 1, 0, 0]
5
[0, 1, 1, 0, 0, 1, 0, 1, 1]
5

*/

/*

int result=0;
        for(int i=0;i<nums.size();i++){
            int sum=nums[i];
            if(sum==goal) result++;
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                if(sum==goal) {
                    result++;
                }
            }
        }
        return result;

*/