#include<bits/stdc++.h>
using namespace std;
class Solution {
    public :
    double averageWaitingTime(vector<vector<int>>& customers){
        double result = 0;
        int currTime = 0;
        for(vector<int> x : customers){
            currTime += currTime < x[0] ? x[0] - currTime : 0;
            currTime += x[1];
            result += currTime - x[0];
        }
        return (double) result/customers.size();
    }
};
int main(){

}