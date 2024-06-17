#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    double FindMedian(vector<int> nums1,vector<int> nums2){
        ios_base::sync_with_stdio(0);
        int m=nums1.size(),n=nums2.size();
        vector<int> newvec;
        int i=0;int j=0;
        while(i<m && j<n){
            if(i<m && j<n&& nums1[i]<nums2[j]){
                newvec.push_back(nums1[i++]);
            }
            else newvec.push_back(nums2[j++]);
        }
        while(i<m) newvec.push_back(nums1[i++]);
        while(j<n) newvec.push_back(nums2[j++]);
        double a=newvec.at(newvec.size()/2);
        double b=(newvec.size()%2==0)? newvec.at(newvec.size()/2-1):0;
        return (b!=0)?(a+b)/2:a;
    }
};
int main(){
    vector<int> nums1,nums2;
    nums1={1,3};
    nums2={2,4,5,6,7};
    Solution S;
    cout<<endl<<"Res : "<<S.FindMedian(nums1,nums2);
}