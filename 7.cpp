#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long int rev=0;
        while(x!=0){
            rev=(rev*10);
            rev=rev+x%10;
            x=x/10;
        }
        return (rev>INT_MAX || rev<INT_MIN)?0:rev;
    }
};
int main(){
    Solution s;
    int x;
    cout<<"Enter a number : ";
    cin>>x;
    cout<<s.reverse(x);
}