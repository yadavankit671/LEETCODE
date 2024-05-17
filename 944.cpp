#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool isSorted(string s){
        for(int i=0; i<s.length()-1; i++){
            if(s[i]>s[i+1]) return false;
        }
        return true;
    }
    public:
    int minDeletionSize(vector<string>& strs) {
        int result = 0;
        for(int i=0;i<strs.at(0).length();i++){
            string s="";
            for(int j=0;j<strs.size()-1;j++){
                if(strs.at(j).at(i) >strs.at(j+1).at(i)) {
                    result++; 
                    break;
                }
            }
        }
        return result;
    }
    /*
            zyx
            wvu
            tsr
    */
};
int main(){
    vector<string> strs={"zyx","wvu","tsr"};
    Solution obj;
    cout<<obj.minDeletionSize(strs);
}