#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void SieveOfEratosthenes(vector<bool> & prime,int n){
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
    }
    public :
    int maximumPrimeDifference(vector<int>& nums) {
        int size=101;
        vector<bool> prime(size,true);
        SieveOfEratosthenes(prime,size);
        prime[0]=false;
        prime[1]=false;
        int firstIndex=-1;
        int secondIndex=-1;
        for(int i=0;i<nums.size();i++){
            if(prime[nums[i]]){
                if(firstIndex==-1){
                    firstIndex=i;
                }
                else{
                    secondIndex=i;
                }
            }
        }
        if(firstIndex==-1 || secondIndex==-1) return 0;
        return secondIndex-firstIndex;
    }
};
int main(){

}