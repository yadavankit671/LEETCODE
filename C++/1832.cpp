#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alpha(26,0);
        for(int i=0;i<sentence.length();i++){
            alpha[sentence[i]-'a']++;
        }
        for(int i=0;i<alpha.size();i++){
            if(alpha[i]==0) return false;
        }
        return true;
    }
};
int main(){

}