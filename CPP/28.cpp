#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()>haystack.length()){
            return -1;
        }
        int index=-1,j=0;
        for(int i=0; i<haystack.length();){
            if(haystack[i]==needle[j]){
                j++;
                if(j==1){
                    index=i;
                }
                i++;
            }
            else{
                i=i-j+1;
                j=0;
                index=-1;
            }
            if(j==needle.length()){
                return index;
            }
        }
        return -1;
    }
};
int main(){
    string haystack = "sadbutsad", needle = "sad";
    Solution s;
    s.strStr(haystack, needle);
}