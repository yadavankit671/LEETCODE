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
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        if(intervals.empty()){
            result.push_back(newInterval);
            return result;
        }
        if(newInterval.at(1)<intervals.at(0).at(0)) result.push_back(newInterval);
        for(int i=0;i<intervals.size();i++){
            if(intervals.at(i).at(0)>newInterval.at(1) && i-1>=0 && intervals.at(i-1).at(1)<newInterval.at(0)) result.push_back(newInterval);
            if(intervals.at(i).at(1)<newInterval.at(0)) result.push_back(intervals.at(i));
            else if(intervals.at(i).at(0)<newInterval.at(0) && intervals.at(i).at(1)>newInterval.at(1)) result.push_back(intervals.at(i));
            else if(intervals.at(i).at(0)>newInterval.at(1)) result.push_back(intervals.at(i));
            else {
                vector<int> temp;
                int start=(intervals.at(i).at(0)<newInterval.at(0))?intervals.at(i).at(0):newInterval.at(0);
                int end=newInterval.at(1);
                while(i<intervals.size()){
                    if(i+1>=intervals.size() || (i+1<intervals.size() && intervals.at(i+1).at(0)>newInterval.at(1))){
                        if(intervals.at(i).at(1)>=newInterval.at(1)) end=intervals.at(i).at(1);
                        else end=newInterval.at(1);
                        temp.push_back(start);
                        temp.push_back(end);
                        result.push_back(temp);
                        break;
                    }
                    else i++;
                }
            }
        }
        if(result.at(result.size()-1).at(1)<newInterval.at(0)) result.push_back(newInterval);
        return result;
    }
};
int main(){
    vector<vector<int>> intervals={};
    vector<int> newIntervals={2,5};
    Solution obj;
    vector<vector<int>> result=obj.insert(intervals,newIntervals);
    print(result);
}

/*

Example 1:


Example 2:


Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

*/