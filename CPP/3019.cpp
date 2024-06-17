#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countKeyChanges(string s) {
        int result = 0;
        for(int i = 0; i < s.length()-1;i++){
            if(tolower(s[i]) !=tolower(s[i+1])) result++;
        }
        return result;
    }
};
int main(){

}