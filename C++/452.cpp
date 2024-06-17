#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> result){
    if(result.empty()){
        cout<<"Empty Result!"<<endl;
        return;
    }
    cout<<"Result : [";
    for(int i=0;i<result.size();i++){
        cout<<"["<<result.at(i).at(0)<<","<<result.at(i).at(1)<<"]";
        if(i+1<result.size()) cout<<",";
    }
    cout<<"]"<<endl;
}
class Solution {
    private: 
    bool doesintersect(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first && a.second==b.second) return true;
        if(b.first<=a.second) return true;
        return false;
    }
    public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        sort(points.begin(),points.end(),[](vector<int> &a, vector<int> &b){
            if(a.at(0)!=b.at(0))
            return a.at(0)<b.at(0);
            else return a.at(1)<b.at(1);
            }
        );
        print(points);
        stack<pair<int,int>> stk;
        int i=0;
        int size=points.size();
        stk.push(make_pair(points.at(i).at(0),points.at(i).at(1)));
        while(i<size){
            pair<int,int> a=stk.top();
            pair<int,int> b=make_pair(points.at(i).at(0),points.at(i).at(1));
            if(doesintersect(a,b)){
                if(b.first>=a.first && b.second<=a.second) stk.top()=b;
            }
            else {
                stk.push(b);
            }
            i++;
        }
        return stk.size();
    }
};
int main(){
    //{{10,16},{2,8},{1,6},{7,12}}
    //{{1,2},{3,4},{5,6},{7,8}}
    //{{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}}
    //{{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}}
    vector<vector<int>> points={{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};
    Solution obj;
    cout<<obj.findMinArrowShots(points);
}