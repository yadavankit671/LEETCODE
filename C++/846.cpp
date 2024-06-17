#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize) return false;
        map<int,int> mp;
        for(int x : hand) mp[x]++;
        while(!mp.empty()){
            int x = mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp.find(x+i)==mp.end()) return false;
                mp[x+i]--;
                if(mp[x+i]==0) mp.erase(x+i);
            }
        }
        return mp.empty();
    }
};
int main(){

}