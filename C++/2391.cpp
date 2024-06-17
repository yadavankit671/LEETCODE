#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    int count(vector<string> &garbage,vector<int> &travel,char ch){
        int result=0;
        int garbageCount=0;
        int index=-1;
        for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage.at(i).length();j++){
                if(garbage[i][j]==ch){
                    garbageCount++;
                    index=i;
                }
            }
        }
        if(garbageCount>0){
            int travdist=accumulate(travel.begin(),travel.begin()+((index<travel.size())?index:travel.size()),0);
            result+=garbageCount+travdist;
        }
        
        return result;
    }
    public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel){
        int result=0;
        result+=count(garbage,travel,'M');
        result+=count(garbage,travel,'P');
        result+=count(garbage,travel,'G');
        return result;
    }
};
int main(){
    vector<string> garbage={"G","P","GP","GG"};
    vector<int> travel={2,4,3};
    Solution obj;
    cout<<obj.garbageCollection(garbage,travel);
}