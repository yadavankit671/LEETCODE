#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool dist(pair<int,int> point1, pair<int,int> point2,int radius){
        int distance=pow(point1.first-point2.first,2)+pow(point1.second-point2.second,2);
        return distance<=(radius*radius);
    }
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;
        for(int i=0;i<queries.size();i++){
            pair<int,int> point1={queries[i].at(0), queries[i].at(1)};
            int radius=queries.at(i).at(2);
            int count=0;
            for(int j=0;j<points.size();j++){
                pair<int,int> point2={points.at(j).at(0), points.at(j).at(1)};
                if(dist(point1,point2,radius)) count++;
            }
            result.push_back(count);
        }
        return result;
    }
};
int main(){
    vector<vector<int>> points={{1,1},{2,2},{3,3},{4,4},{5,5}};
    vector<vector<int>> queries={{1,2,2},{2,2,2},{4,3,2},{4,3,3}};
    Solution obj;
    vector<int> result=obj.countPoints(points,queries);
    for(auto x: result) cout<<x<<",";
}