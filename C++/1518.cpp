#include<bits/stdc++.h>
using namespace std;
class Solution {
    public :
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            int rem = empty / numExchange;
            result += rem;
            empty = rem + (empty % numExchange);
        }
        return result;
    }
};
int main(){

}