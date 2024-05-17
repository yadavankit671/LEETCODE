#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=0; i < nums.size()-1;){
            if(nums.at(i) ==nums.at(i+1)){
                nums.erase(nums.begin()+i,nums.begin()+i+1);
            }
            else i++;
        }
        return nums.size();
    }
};
int main(){
    Solution s;
    vector<int> v={0,0,1,1,1,2,2,3,3,4};
    cout<<s.removeDuplicates(v)<<endl<<endl;
    for(int i;i<=v.size();i++){
        cout<<v[i]<<endl;
    }
}