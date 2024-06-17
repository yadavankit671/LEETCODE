#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for(vector<int> arr : grid){
            int start=0;
            if(arr[start]<0){
                result+=arr.size();
                continue;
            }
            int end=arr.size()-1;
            if(arr[end]>=0) continue;
            while(start<end){
                int mid=(start+end)/2;
                if(arr[mid]<0) end=mid;
                else start=mid+1;
            }
            result+=arr.size()-start;
        }
        return result;
    }
};
int main(){
    vector<vector<int>> grid={{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    Solution obj;
    cout<<obj.countNegatives(grid)<<endl;
    return 0;
}