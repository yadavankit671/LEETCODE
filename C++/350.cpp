#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /*
        using Map : O(nlog(n))
        map<int,int> freq;
        for(int x : nums1) {
            freq[x]++;
        }
        vector<int> result;
        for(int x : nums2){
            if(freq[x]>0){
            result.push_back(x);
            freq[x]--;
            }
        }
        return result;
        */
        // time : O(n+m)
        vector<int> result;
        int array[1001];
        for(int i=0;i<nums1.size();i++){
            array[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(array[nums2[i]]>0){
                result.push_back(nums2[i]);
                array[nums2[i]]--;
            }
        }
        return result;
    }
};
int main(){

}