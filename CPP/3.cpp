#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(256,-1);
        int maxl=0,count=-1;
        for(int i=0;i<s.size();i++){
            if(arr[s[i]]>count){
                count=arr[s[i]];
            }
            arr[s[i]]=i;
            maxl=(maxl>i-count)?maxl:i-count;
        }
        return maxl;
    }
};
int main(){

}