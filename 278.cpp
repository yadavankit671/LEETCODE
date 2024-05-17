#include<bits/stdc++.h>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    private:
    int k;
    int n;
    bool isBadVersion(int x){
        return (x==k);
    }
public:
    Solution(int k,int n){
        this->k = k;
        this->n = n;
    }
    int firstBadVersion() {
        if (n<=1) return 1;
        int start=1;
        int end=n;
        while(start<end){
            int mid=start+(end-start)/2;
            if(isBadVersion(mid)) end=mid;
            else start=mid+1;
        }
        return end;
    }
};
int main(){ // k,n
    Solution s(4,4);
    cout<<s.firstBadVersion();
}