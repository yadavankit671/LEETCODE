#include<bits/stdc++.h>
using namespace std;
void print(vector<int> result){
    if(result.empty()){
        cout<<"[]";
        return;
    }
    cout<<"Result : ["<<result.at(0)<<","<<result.at(1)<<"]"<<endl;
}
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        ios_base::sync_with_stdio(false);
        if(tomatoSlices==0 && cheeseSlices==0) return {0,0};
        int y=(4*cheeseSlices-tomatoSlices)/2;
        int x=cheeseSlices-y;
        int sum=(4*x)+(2*y);
        if(sum!=tomatoSlices || (x+y)!=cheeseSlices) return {};
        if(x<0 || y<=0 ) return {};
        return {x,y};
    }
};
int main(){
    int tomatoSlices=2537427, cheeseSlices=860448;
    Solution obj;
    vector<int> result=obj.numOfBurgers(tomatoSlices,cheeseSlices);
    print(result);
}