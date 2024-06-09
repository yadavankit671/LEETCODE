#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        sort(barcodes.begin(), barcodes.end());
        
        return barcodes;
    }
};
int main(){
    vector<int> barcodes={1,2,1,1,2,2};
    Solution obj;
    vector<int>  res=obj.rearrangeBarcodes(barcodes);
    for(int x : res ) cout<<x<<endl;
}