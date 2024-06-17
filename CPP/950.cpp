#include<bits/stdc++.h>
using namespace std;
class Solution {

    private: 

    vector<int>  push(vector<int> &result,int k){
        int x=result.back();
        result.pop_back();
        vector<int> temp;
        temp.push_back(k);
        temp.push_back(x);
        for(int i=0;i<result.size();i++) temp.push_back(result[i]);
        return temp;
    }

    public:

    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if(deck.size()<=2) {
            sort(deck.begin(),deck.end());
            return deck;
        }
        sort(deck.begin(),deck.end());
        vector<int> result;
        result.push_back(deck.at(deck.size()-2));
        result.push_back(deck.at(deck.size()-1));
        int i=deck.size()-3;
        for(;i>=0;i--){
            result = push(result,deck.at(i));
        }
        return result;
    }
};
int main(){
    vector<int> deck={17,13,11,2,3,5,7};
    // Sorted : 2,3,5,7,11,13,17 || Result : 2,13,3,11,5,17,7
    Solution obj;
    vector<int> result=obj.deckRevealedIncreasing(deck);
    cout<<"\n\nResult : ";
    for(int x: result) cout<<x<<",";
}