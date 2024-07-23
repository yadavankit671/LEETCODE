#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCollisions(string directions) {
        ios_base::sync_with_stdio(false); // to handle the io
        cin.tie(NULL);
        cout.tie(NULL);
        int result = 0, size = directions.length();
        int start = 0;
        int end = size - 1;
        while(start < size && directions.at(start) == 'L') start++;
        while(end >= 0 && directions.at(end) == 'R') end--;
        while(start <= end){
            if(directions.at(start) != 'S') result++;
            start++;
        }
        return result;
    }
};
int main(){

}