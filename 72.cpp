#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.length()+1;
        int len2=word2.length()+1;
        vector<vector<int>> matrix(len1,vector<int>(len2));
        for(int i=0;i<len2;i++) matrix.at(0).at(i)=i;
        for(int i=1;i<len1;i++) matrix.at(i).at(0)=i;
        for(int i=1;i<len1;i++){
            for(int j=1;j<len2;j++){
                if(word1.at(i-1)==word2.at(j-1)){
                    matrix.at(i).at(j)=matrix.at(i-1).at(j-1);
                }
                else{
                    int x=matrix.at(i-1).at(j);
                    int y=matrix.at(i).at(j-1);
                    int z=matrix.at(i-1).at(j-1);
                    matrix.at(i).at(j)=min(x,min(y,z))+1;
                }
            }
        }
        return matrix.at(len1-1).at(len2-1);
    }
};
int main(){
    Solution obj;
    string word1="horse";
    string word2="ros";
    cout<<obj.minDistance(word1, word2)<<endl;
}