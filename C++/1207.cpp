#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        if(arr.size()==0) return true;
        sort(arr.begin(),arr.end());  // use set value as key and repetation as data
        vector<pair<int,int>> list;
        for(int i=0;i<arr.size();i++){
            if(list.size()==0) list.push_back(make_pair(1,arr[i]));
            else{
                if(arr[i]==list[list.size()-1].second){
                    list[list.size()-1].first++;
                }
                else list.push_back(make_pair(1,arr[i]));
            }
        }
        sort(list.begin(),list.end());
        for(int i=0;i<list.size()-1;i++){
            if(list[i].first==list[i+1].first) return false;
        }
        return true;
    }
    void print(vector<pair<int,int>> list){
        for(int i=0;i<list.size();i++){
            cout<<list[i].first<<" "<<list[i].second<<endl;
        }
    }
};
int main(){
    Solution obj;
    vector<int> list={1,2};
    cout<<obj.uniqueOccurrences(list);
}