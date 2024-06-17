#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int percentageLetter(string s, char letter) {
        float counter=0;
        for(auto x: s) if(x==letter) counter++;
        counter*=100;
        return floor(counter/s.length());
    }
};
int main(){
    string str="vmvvvvvzrvvpvdvvvvyfvdvvvvpkvvbvvkvvfkvvvkvbvvnvvomvzvvvdvvvkvvvvvvvvvlvcvilaqvvhoevvlmvhvkvtgwfvvzy";
    char letter='v';
    Solution obj;
    cout<<obj.percentageLetter(str,letter)<<endl;
}