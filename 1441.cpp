#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int index=0;
        for(int i=0;index<target.size();i++) {
            result.push_back("Push");
            if(target[index]!=i+1){
                result.push_back("Pop");
            }
            else index++;
        }
        return result;
    }
    void print(vector<int> target){
        if(target.size()==0) return;
        cout<<endl<<"Stack: "<<target[0];
        for(int i=1;i<target.size();i++){
            cout<<", "<<target[i];
        }
        cout<<endl;
    }
    void print(vector<string> target){
        if(target.size()==0) return;
        cout<<endl<<"Result: "<<target[0];
        for(int i=1;i<target.size();i++){
            cout<<", "<<target[i];
        }
        cout<<endl;
    }
};
int main(){
    vector<int> target={1,3};
    int n=3;
    Solution s;
    vector<string> result=s.buildArray(target, n);
    //if (result.size()==0) return;
    cout<<endl<<"Result: {"<<result[0];
    for(int i=1;i<result.size();i++){
        cout<<", "<<result[i];
    }
    cout<<"}"<<endl;
}