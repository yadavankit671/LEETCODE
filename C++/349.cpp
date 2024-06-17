#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> intersections;
        vector<int> result;
        for(int i=0;i<nums1.size();i++) intersections.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++){
            if(intersections.find(nums2[i])!=intersections.end()){
                result.push_back(nums2.at(i));
                intersections.erase(nums2.at(i));
            }
        }
        return result;
    }
};
int main(){
    vector<int> nums1={};
    vector<int> nums2={};
    Solution obj;
    vector<int> result=obj.intersection(nums1,nums2);
}