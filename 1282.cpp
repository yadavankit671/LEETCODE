#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> result){
    if(result.empty()){
        cout<<"List is empty !!"<<endl;
        return;
    }
    cout<<"List :"<<endl;
    for(auto x: result){
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print(map<int,vector<int>> list){
    for(auto x:list){
            cout<<x.first<<"\t";
            for(int i=0;i<x.second.size();i++) cout<<x.second.at(i)<<",";
            cout<<endl;
        }
}
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> list;
        for(int i=0;i<groupSizes.size();i++) list[groupSizes[i]].push_back(i);
        vector<vector<int>> result;
        for(auto itr=list.begin();itr!=list.end();){
            vector<int> temp;
            int size=itr->first;
            while (temp.size()<size && !itr->second.empty()){
                temp.push_back(itr->second.at(itr->second.size()-1));
                itr->second.pop_back();
            }
            if(itr->second.size()==0) itr++;
            if(temp.size()>0)   result.push_back(temp);
        }
        return result;
    }
};
int main(){
    vector<int> groupSizes ={2,2,1,1,1,1,1,1};
    Solution obj;
    print(obj.groupThePeople(groupSizes));
}