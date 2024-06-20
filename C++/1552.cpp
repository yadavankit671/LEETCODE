#include<bits/stdc++.h>
using namespace std;
class Solution {
    // 1,2,3,4,5,6,7,8,9 -->m=4
    // 1,3,6,9
    private: 
    bool solve(vector<int> & position,int m,int midForce){
        int prevValue=position[0];
        int count=1;
        for(int i=1;i<position.size();i++){
            if(position[i]-prevValue>=midForce) {
                count++;
                prevValue=position[i];
            }
            if(count>=m) break;
        }
        return count>=m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int minForce=1;
        int maxForce=position[position.size()-1]-minForce;
        int ans=0;
        while(minForce<=maxForce){
            int midForce=minForce+(maxForce-minForce)/2;
            if(solve(position,m,midForce)){
                ans=midForce;
                minForce=midForce+1;
            }
            else{
                maxForce=midForce-1;
            }
        }
        return ans;
    }
};
int main(){

}