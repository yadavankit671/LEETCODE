#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        int parent=kthGrammar(n-1,k/2+k%2);
        if(parent==1){
            return (k%2==0)?0:1;
        }
        else{
            return (k%2==0)?1:0;
        }
    }
};
int main(){
    Solution s;
    cout<<s.kthGrammar(15,5);
}