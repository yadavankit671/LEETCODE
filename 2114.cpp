#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int counter=INT_MIN;
        for(int i=0;i<sentences.size();i++){
            int temp=0;
            for(int j=0;j<sentences.at(i).length();j++){
                if(sentences.at(i).at(j)==' ' || sentences.at(i).at(j)=='.') temp++;
            }
            temp++;
            if(temp>counter) counter=temp;
        }
        return counter;
    }
};
int main(){
    Solution obj;
    vector<string> sentences={"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    cout<<obj.mostWordsFound(sentences);
}