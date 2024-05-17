#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        if(nums.size()==1) return {to_string(nums[0])};
        vector<string> result;
        int prev=nums[0];
        int i=1;
        for(; i<nums.size();){
            if(prev+1==nums[i]){
                int temp=prev;
                prev=nums[i];
                i=i+1;
                while(i<nums.size() && prev+1==nums[i]){
                    prev=nums[i];
                    i++;
                }
                string res="";
                res=res+to_string(temp);
                res=res+"->";
                res=res+to_string(prev);
                result.push_back(res);
                if(i<nums.size())
                prev=nums[i];
                i++;
            }
            if(i<nums.size() && prev+1!=nums[i]){
                result.push_back(to_string(prev));
                prev=nums[i];
                i++;
            }
        }
        if( nums[nums.size()-2]+1!=nums[nums.size()-1]){
            result.push_back(to_string(nums[nums.size()-1]));
        }
        return result;
    }
    void print(vector<string>& result){
        if(result.size()==0){
            cout<<"Empty Vector !!"<<endl;
            return;
        }
        cout<<"Vector :{"<<result[0];
        for(int i=1;i<result.size();i++){
            cout<<","<<result[i];
        }
        cout<<"}"<<endl;
    }
};
int main(){
    Solution obj;
    vector<int> nums={0,1,2,3,5,7,8,11};
    vector<string> result=obj.summaryRanges(nums);
    obj.print(result);
}