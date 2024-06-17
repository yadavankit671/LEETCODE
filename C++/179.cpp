#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool allZeros(vector<int> & nums){
        for (int x : nums) if(x!=0) return false;
        return true;
    }
    static bool cmp(string &a,string &b){
        if(a[0]>b[0]) return true;
        else if(a[0]<b[0]) return false;
        string temp1=a+b;
        string temp2=b+a;
        int i=0;int j=0;
        while(i<temp1.length() && j<temp2.length()){
            if(temp1[i]>temp2[j]) return true;
            else if(temp1[i]<temp2[j]) return false;
            i++;j++;
        }
        return true;
    }
    public: 
    string largestNumber(vector<int>& nums) {
        // for zeros 
        if(allZeros(nums)) return "0"; 
        vector<string> buff;
        for(int i=0;i<nums.size();i++){
            buff.push_back(to_string(nums[i]));
        }
        sort(buff.begin(),buff.end(),cmp);
        string result="";
        for(int i=0;i<buff.size();i++) result+=buff[i];
        return result;
    }
};
int main(){
    vector<int> nums={3,30,34,5,9};
    Solution obj;
    cout<<obj.largestNumber(nums)<<endl;
}