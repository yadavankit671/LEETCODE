#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<long long> prefix;
        prefix.push_back(0);
        for(int i=0;i<nums.size();i++) {
            prefix.push_back(nums.at(i)+prefix.at(prefix.size()-1));
        }
        vector<long long> result;
        int i=0;
        while(result.size()!=queries.size() && i<queries.size()){
            long long small=lower_bound(nums.begin(),nums.end(),queries.at(i))-nums.begin();
            long long large=nums.size()-small;
            long long actualSmall=prefix.at(small);
            long long actualLarge=prefix.at(prefix.size()-1)-prefix.at(small);
            long long idealSmall=queries.at(i)*small;
            long long idealLarge=queries.at(i)*large;
            long long temp=abs(idealSmall-actualSmall)+abs(actualLarge-idealLarge);
            result.push_back(temp);
            i++;
        }
        return result;
    }
};
int main(){
    vector<int> nums={3,1,6,8};
    vector<int> queries={1,5};
    Solution obj;
    vector<long long> result=obj.minOperations(nums,queries);
    cout<<endl;
    for(auto x: result) cout<<x<<",";
}
/*

            cout<<actualSmall<<"\t"<<actualLarge<<"\t"<<idealSmall<<"\t"<<idealLarge<<endl;

*/