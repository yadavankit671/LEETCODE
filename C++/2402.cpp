#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> arr){
    if(arr.empty()){
        cout<<"Empty array!"<<endl;
        return;
    }
    cout<<"Array"<<endl;
    for(auto x: arr){
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<",";
        }
        cout<<endl;
    }
}
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(),[](vector<int>&a,vector<int>&b){return a[0]<b[0];});
        print(meetings);
        int meetingsCompleted=0;
        int totalmeetings=meetings.size();
        vector<vector<int>>meetingsroom(n);
        vector<bool>free(n,true);
        int current_time=0;
        //////////roomno    start-end
        vector<pair<int,pair<int,int>>> crnt_meetings;
        crnt_meetings.clear();
        int meetingNo=0;
        while(meetingsCompleted!=totalmeetings){
            cout<<meetingsCompleted<<"\t"<<totalmeetings<<"\t"<<current_time<<endl;
            if(!crnt_meetings.empty())
            for(int i=0;crnt_meetings.size();i++){
                cout<<"here";
                if(crnt_meetings[i].second.second==current_time) {
                    meetingsCompleted++;
                    crnt_meetings[i].second.first=-1;
                    crnt_meetings[i].second.second=-1;
                    free[crnt_meetings[i].first]=true;
                }
            }
            cout<<"here11"<<endl;
            for(int i=0;i<free.size();i++){
                if(free[i]){
                    meetingsroom[i].push_back(meetingNo);
                    crnt_meetings.push_back(make_pair(i,make_pair(current_time,meetings[meetingNo][1]-meetings[meetingNo][0]+current_time)));
                    meetingNo++;
                    free[i]=false;
                    break;
                }
            }
            current_time++;
        }
        sort(meetingsroom.begin(),meetingsroom.end(),[](vector<int> &a,vector<int> &b){ return a.size()>b.size(); });
        print(meetingsroom);
        return meetingsCompleted;
    }
};
int main(){
    vector<vector<int>> meetings={{1,20},{3,5},{2,10},{4,9},{6,8}};
    int n=3;
    Solution obj;
    cout<<obj.mostBooked(n,meetings)<<endl;
}