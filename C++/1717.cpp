#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maximumGain(string str, int x, int y){
        int score = 0;
        char high = 'a';
        char low = 'b';
        if (x < y){
            swap(x, y);
            swap(high, low);
        }
        int highCount = 0, lowCount = 0;
        for (char ch : str){
            if (ch == high) highCount++;
            else if (ch == low){
                if (highCount > 0){
                    highCount--;
                    score += x;
                }
                else lowCount++;
            }
            else{
                score += min(highCount, lowCount) * y;
                highCount = lowCount = 0;
            }
        }
        score += min(highCount, lowCount) * y;
        return score;
    }
};
int main(){
    // s = "cdbcbbaaabab", x = 4, y = 5
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    Solution obj;
    cout << obj.maximumGain(s, x, y);
}