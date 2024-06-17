#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> list;
        for(auto x: arr) list[x]++;
        for(auto y: arr) {
            if(list[y]==1){
                k--;
            }
            if(k==0) return y;
        }
        return "";
    }
};
int main(){
    vector<string> arr={"ki","ci","vs","sjoxb"};
    int k=2;
    Solution obj;
    cout<<obj.kthDistinct(arr,k);
}