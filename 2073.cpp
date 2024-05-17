#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        if(tickets.at(k)==1) return k;
        while(tickets.at(k)!=0){
            for(int i=0;i<tickets.size();i++){
                if(tickets.at(i)>0){
                    tickets[i]--;
                    time++;
                }
                if(tickets.at(k)==0) break;
            }
        }
        return time;
    }
};
int main(){

}