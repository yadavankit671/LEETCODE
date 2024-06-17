#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=left;
        left++;
        while(left<=right){
            ans=ans&&left;
            left++;
        }
        return ans;
    }
};
int main(){

}