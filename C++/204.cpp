#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool>primes(n,true);
        int result = 0;
        for(int i=2;i*i<n;i++){
            if(primes[i]){
                fill(primes,i,n);
            }
        }
        for(int i=3;i<primes.size();i+=2){
            if(primes[i]) {cout<<i<<",";result++;}
        }
        cout<<endl;
        return result+1;
    }
    private:
    void fill(vector<bool>& primes,int x,int n){
        for(int i=x*x;i<n;i+=x){
            primes[i]=false;
        }
        return;
    }
};
int main(){
    Solution s;
    cout<<endl<<s.countPrimes(INT_MAX/10);
}