#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotInteger(int n) {
        int j=n;
        int sum=0;
        while(j>=0){
            sum+=j;
            int coff=2*(sum*-1);
            int d=1-(4*(coff));
            if(d>0){
                int ans1=(-1+sqrt(d))/(2);
                int ans2=(-1-sqrt(d))/(2);
                cout<<sum<<"\t"<<ans1<<"\t"<<ans2<<endl;
                if(ans1==j) return j;
                if(ans2==j) return j;
            }
            j--;
        }
        return -1;
    }
};
int main(){
    Solution obj;
    cout<<obj.pivotInteger(8);
}