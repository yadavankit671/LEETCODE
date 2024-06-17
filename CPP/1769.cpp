#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ones;
        vector<int> result;
        for(int i=0;i<boxes.length();i++) if(boxes.at(i)=='1') ones.push_back(i);
        for(int i=0;i<boxes.length();i++){
            int temp=0;
            for(int j=0;j<ones.size();j++){
                if(ones[j]!=i){
                    temp+=abs(ones[j]-i);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};
int main(){
    string boxes="110";
    Solution obj;
    vector<int> result=obj.minOperations(boxes);
    for(auto x: result) cout<<x<<",";
}