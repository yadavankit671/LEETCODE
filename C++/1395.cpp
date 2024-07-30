#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numTeams(vector<int>& rating) {
        /*----------------------------O(n^2----------------------------*/
        int result = 0;
        int n = rating.size();
        for(int j = 1; j < n -1; ++j){
            int y = rating[j];
            int leftSmall = 0;
            int leftLarge = 0;
            int rightSmall = 0;
            int rightLarge = 0;
            for(int i = 0; i < j; ++i){
                int x = rating[i];
                if(x < y) leftSmall ++;
                else if(x > y) leftLarge ++;
            }
            for(int i = j + 1; i < n; ++i){
                int x = rating[i];
                if(x < y) rightSmall ++;
                else if(x > y) rightLarge ++;
            }
            result += leftSmall * rightLarge + leftLarge * rightSmall;
        }
        return result;
    }
};
int main(){

}

/*
----------------------------BruteForce Approach----------------------------
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int result = 0;
        int n = rating.size();
        for(int i = 0; i < n; i++){
            int x = rating[i];
            for(int j = i + 1; j < n; ++j){
                int y = rating[j];
                if(y == x) continue;
                for(int k = j + 1; k < n; ++k){
                    int z = rating[k];
                    if( z == y || z == x) continue;
                    else if( x > y && y > z) result ++;
                    else if( x < y && y < z) result ++;
                }
            }
        }
        return result;
    }
};

*/