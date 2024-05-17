#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPoints(string rings) {
        vector<string> rods(10,"");
        for(int i=1;i<rings.length();i+=2){
            char c=rings[i-1];
            int index=rings[i]-'0';
            if(find(rods[index].begin(),rods[index].end(),c)==rods[index].end()){
                rods[index].push_back(c);
            }
        }
        int counter=0;
        for(int i=0;i<rods.size();i++){
            if(rods[i].length()>=3) counter++;
        }
        return counter;
    }
};
int main(){
    string rings="B0B6G0R6R0R6G9B1G1R1";
    Solution obj;
    cout<<obj.countPoints(rings)<<endl;
}