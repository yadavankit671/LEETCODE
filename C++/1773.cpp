#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int counter=0;
        for(auto x: items){
            if (ruleKey=="type"){
                if(x.at(0)==ruleValue) counter++;
            }
            else if(ruleKey=="color"){
                if(x.at(1)==ruleValue) counter++;
            }
            else {
                if(x.at(2)==ruleValue) counter++;
            }
        }
        return counter;
    }
};
int main(){
    vector<vector<string>> items={{"phone","blue","pixel"},{"computer","silver","lenovo"},{"phone","gold","iphone"}};
    string ruleKey="type";
    string ruleValue="phone";
    Solution obj;
    cout<<obj.countMatches(items,ruleKey,ruleValue);

}