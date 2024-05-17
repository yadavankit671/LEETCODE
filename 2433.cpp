#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> findArray(vector<int>& pref) {
        if(pref.size()<=1) return pref;
        vector<int> result;
        result.push_back(pref.at(0));
        int prev=pref[0];
        for(int i=1;i<pref.size();i++){
            result.push_back(pref[i]^prev);
            prev=pref[i];
        }
        return result;
    }
    void print(vector<int> result){
        if( result.size()==0 ){
            cout<<"Vector is empty!"<<endl;
            return;
        }
        cout<<"List : {"<<result.at(0);
        for(int i=1;i<result.size();i++){
            cout<<","<<result.at(i);
        }
        cout<<"}"<<endl;
    }
};
int main(){
    vector<int>pref={5,2,0,3,1};
    Solution obj;
    vector<int>result=obj.findArray(pref);
    obj.print(result);
}