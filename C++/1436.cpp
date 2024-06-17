#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        if( paths.size()==1) return paths[paths.size()-1].back();
        vector<string> first;
        vector<string> last;
        for(auto itr=paths.begin(); itr!=paths.end(); itr++) {
            first.push_back(itr->front());
            last.push_back(itr->back());
        }
        for( int i=last.size()-1; i>=0; i--){
            if(find(first.begin(),first.end(),last[i])==first.end()){
                return last[i];
            }
            else last.pop_back();
        }
        return "";
    }
};
int main(){
    vector<vector<string>> paths={{"A","B"}};
    Solution obj;
    cout<<obj.destCity(paths)<<endl;
}