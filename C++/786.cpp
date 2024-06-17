#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        if(k==1) return {arr[0],arr[arr.size()-1]};
        map<double,pair<int,int>> buffer;
        for(int i=0;i<arr.size();i++) {
            for(int j=i+1;j<arr.size();j++){
                double x=arr[i];
                double y=arr[j];
                double ans=x/y;
                buffer[ans]={arr[i],arr[j]};
            }
        }
        map<double,pair<int,int> > ::iterator itr=buffer.begin();
        while(itr != buffer.end()){
            k--;
            if(k==0) return {itr->second.first,itr->second.second};
            itr++;
        }
        return {-1,-1};
    }
};
int main(){
    vector<int> arr={1,2,3,5,7,11,13,17,19,23,29,31,37,43,47,53,59,61,67,71,79,83,89,97};
    Solution obj;
    obj.kthSmallestPrimeFraction(arr,1);
}