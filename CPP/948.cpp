#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int i=0;int j=tokens.size()-1;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                power-=tokens[i];
                i++;
            }
            else if(tokens[i]>power&& score >0){
                if(i+1==j)break;
                score--;
                power+=tokens[j];
                j--;
            }
            else if(tokens[i]>power && score==0) return 0;
        }
        return score;
    }
};
int main(){
    vector<int> tokens={100,200,300,400};
    int power=200;
    Solution obj;
    cout<<obj.bagOfTokensScore(tokens,power);
}