#include<bits/stdc++.h>
using namespace std;
class Solution {
    public :
    int findCenter(vector<vector<int> > &edges){
        int x = edges[0][0];
        int y = edges[0][1];
        if (x==edges[1][0] || x==edges[1][1]) return x;
        return y;
        
        // return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};
int main(){

}