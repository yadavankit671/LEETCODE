#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    int getCount(int n){
        int ones=0;
        while(n>0){
            if(n%2==1) ones++;
            n/=2;
        }
        return ones;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> buffer;
        for(int i=0;i<arr.size();i++){
            int temp=getCount(arr[i]);
            buffer.push_back(make_pair(arr.at(i),temp));
        }
        sort(buffer.begin(),buffer.end(),[](pair<int,int>&a ,pair<int,int>&b){
            if(a.second==b.second) 
                return a.first<b.first;
            return a.second<b.second;
        });
        vector<int> result;
        for(auto x: buffer) result.push_back(x.first);
        return result;
    }
};
int main(){
    vector<int> arr={0,1,2,3,4,5,6,7,8};
    Solution obj;
    vector<int> res=obj.sortByBits(arr);
    for(auto x:res) cout<<x<<",";
}