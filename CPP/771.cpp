#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char, int> list;
        int result = 0;
        for(int i=0;i<jewels.length();i++) list[jewels[i]]=1;
        for(int i=0;i<stones.length();i++) if(list[stones[i]]) result++;
        return result;
    }
};
int main(){
    string jewels="aA";
    string stones="aaAbbB";
    Solution obj;
    cout<<obj.numJewelsInStones(jewels,stones);
}