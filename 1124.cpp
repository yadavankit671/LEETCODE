#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int result = 0;
        vector<int> temp;
        for(auto x:hours) 
            if(x>8) temp.push_back(1); 
            else temp.push_back(-1);
        for(int i=0;i<temp.size();i++){
            int sum=temp[i];
            result=max(result,sum);
            for(int j=i+1;j<hours.size();j++){
                sum+=temp[j];
                if(sum==1) result=max(result,j-i);
            }
        }
        return result;
    }
};
int main(){
    vector<int> hours={6,6,9};
    Solution obj;
    cout<<obj.longestWPI(hours)<<endl;
}