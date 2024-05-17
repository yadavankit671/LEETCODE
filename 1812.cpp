#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if((coordinates[0]+coordinates[1]-'0')%2!=0) return true;
        else return false;
    }
};
int main(){
    Solution obj;
    string coordinates="a1";
    cout<<obj.squareIsWhite(coordinates);
}