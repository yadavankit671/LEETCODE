#include<bits/stdc++.h>
using namespace std;
class Solution {
    public :
    bool threeConsecutiveOdds(vector<int> &arr){
        int count=0;
        for(int x : arr){
            if(x%2!=0) count++;
            else count=0;
            if(count==3) return true;
        }
        return false;
    }
};
int main(){

}