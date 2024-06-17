#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int size=asteroids.size();
        double mas=mass;
        for(int i=0;i<size;i++){
            if(mas<asteroids.at(i)) return false;
            else mas+=asteroids.at(i);
            if(mas>INT_MAX) mas=INT_MAX;
        }
        return true;
    }
};
int main(){

}