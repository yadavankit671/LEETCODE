#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        //0,1,2,3,
        int mid=s.length()/2; 
        int firsthalf=0;
        int otherhalf=0;
        for(int i=0;i<s.length();i++) {
            char c=tolower(s[i]);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                if(i<mid)   firsthalf++;
                else otherhalf++;
        }
        return firsthalf==otherhalf;
    }
};
int main(){
    string str="AbCdEfGh";
    Solution obj;
    cout<<obj.halvesAreAlike(str)<<endl;
}