#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int low=0,high=x;
        recursion:
        if(low<=high){
            double mid=(high+low)/2;
            if ((mid*mid<=x) && (mid+1)*(mid+1)>x)
                return mid;
            else if(mid*mid<x){
                low=mid+1;
                goto recursion;
            }
            else {
                high=mid-1;
                goto recursion;
            }
        }
        return low;
    }
};
int main(){
    Solution s;
    cout<<s.mySqrt(8);
}