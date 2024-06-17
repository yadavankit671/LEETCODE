#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        if(n==1) return 1;
        int j=0;
        int k=1;
        int counter=0;
        while(counter<n-1){
            int sum=j+k;
            j=k;
            k=sum;
            counter++;
        }
        return k;
    }
};
int main(){

}