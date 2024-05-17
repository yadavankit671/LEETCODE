#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res={1,2};
        if(numbers.size()==2) return res;
        int i=0;
        int end=numbers.size()-1;
        while(i<end){
            int temp=numbers[i]+numbers[end];
            if(temp<target){
                i++;
            }
            else if(temp==target){
                res[0]=i+1;
                res[1]=end+1;
                return res;
            }
            else{
                end--;
            }
        }
        return res;
    }
};
int main(){

}