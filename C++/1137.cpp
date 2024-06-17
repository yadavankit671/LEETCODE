#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        int start=0;
        int first=1;
        int second=1;
        if(n<=2){
            if(n==0) return start;
            else if(n==1) return first;
            else return second;
        }
        int counter=0;
        while(counter<n-1){
            int sum=start+first+second;
            cout<<sum<<endl;
            start=first;
            first=second;
            second=sum;
            counter++;
        }
        return second;
    }
};
int main(){
    Solution obj;
    cout<<obj.tribonacci(25)<<endl;
}