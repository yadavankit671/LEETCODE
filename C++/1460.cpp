#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> mp(1001,0);
        for(int x : arr) mp[x]++;
        for(int x : target) mp[x]--;
        for(int x : mp) if(x != 0) return false;
        return true;
    }
};
int main(){

}