#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,int> list;
        for(auto x:words){
            string temp="";
            for(int i=0;i<x.length();i++){
                temp+=morse[x[i]-'a'];
            }
            list[temp]=1;
        }
        return list.size();
    }
};
int main(){
    vector<string> words={"gin","zen","gig","msg"};
    Solution obj;
    cout<<obj.uniqueMorseRepresentations(words);
}
/*

".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."

*/