#include<bits/stdc++.h>
using namespace std;

class AllOne {
    private:
    map<string, int> keyMap;
    map<int, set<string> > countMap;
public:
    AllOne() {
        keyMap.clear();
        countMap.clear();
    }
    
    void inc(string key) {
        if(keyMap.find(key)==keyMap.end()){
            keyMap[key] = 1;
            countMap[1].insert(key);
        } else{
            int currCount = keyMap[key];
            keyMap[key]++;
            countMap[currCount].erase(key);
            if(countMap[currCount].empty()) countMap.erase(currCount);
            countMap[currCount + 1].insert(key);
        }
    }
    void dec(string key) {
        if(keyMap.find(key) == keyMap.end()) return;
        int currCount = keyMap[key];
        if(currCount == 1){
            keyMap.erase(key);
            countMap[1].erase(key);
            if(countMap[1].empty()) countMap.erase(1);
        } else{
            keyMap[key]--;
            countMap[currCount].erase(key);
            if(countMap[currCount].empty()) countMap.erase(currCount);
            countMap[currCount - 1].insert(key);
        }
    }
    
    string getMaxKey() {
        if(countMap.empty()) return "";
        return *(countMap.rbegin()->second.begin());
    }
    
    string getMinKey() {
        if(countMap.empty()) return "";
        return *(countMap.begin()->second.begin());
    }
};

int main(){

}