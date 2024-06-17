#include<bits/stdc++.h>
using namespace std;

class AllOne {
    private: 
    vector<pair<string,int>>buffer;
    string max_key;
    string min_key;
    
    void update_keys(){
        sort(buffer.begin(), buffer.end(),[](const pair<string,int>&a,const pair<string,int>&b){return a.second<b.second;});
        max_key=buffer.at(buffer.size()-1).first;
        min_key=buffer.at(0).first;
    }
public:
    AllOne() {   
    }
    void inc(string key) {
        for(auto x=buffer.begin();x!=buffer.end();x++){
            if(x->first==key){
                x->second++;
                update_keys();
                return;
            }
        }
        update_keys();
    }
    
    void dec(string key) {
        for(auto x=buffer.begin();x!=buffer.end();x++){
            if(x->first==key){
                if(x->second<=1) buffer.erase(x);
                else x->second--;
                update_keys();
                return;
            }
        }
    }
    
    string getMaxKey() {
        return max_key;
    }
    
    string getMinKey() {
        return min_key;
    }
};

int main(){
    vector<int> list;
    vector<int> list2;
}