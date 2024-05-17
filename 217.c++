#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return false;
        set<int> buffer;
        for(int i=0; i<nums.size(); i++){
            buffer.insert(nums[i]);
            if(buffer.size()<i) return true;
        }
        if(buffer.size()<nums.size()) return true;
        return false;
    }
};
int main(){
    vector<int> nums;
    Solution s;
    /*for(int i=0;i<100000;i++){
        nums.push_back(i);
    }
    if (s.containsDuplicate(nums)) cout<<"Contains Duplicate"<<endl;
    else cout<<"NO Duplicate"<<endl;
    nums.clear();*/
    nums.push_back(3);
    nums.push_back(4);
    if (s.containsDuplicate(nums)) cout<<"Contains Duplicate"<<endl;
    else cout<<"NO Duplicate"<<endl;
}
//

// sort(nums.begin(), nums.end());
//         for(int i = 0; i < nums.size()-1;i++){
//             if(nums.at(i)==nums.at(i+1)) return true;
//         }