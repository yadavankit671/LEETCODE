#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int result=-1;
        int i=0;int j=0;
        int num1size=nums1.size();
        int num2size=nums2.size();
        while(i<num1size && j<num2size){
            if(nums1[i]==nums2[j]){
                result=nums1[i];
                break;
            }
            if(i<num1size && j<num2size && nums1[i]>nums2[j]) i++;
            else if(i<num1size && j<num2size && nums1[i]<nums2[j]) j++;
        }
        return result;
    }
};
int main(){

}