#include<bits/stdc++.h>
using namespace std;
class MyHashSet {
    private:
    unordered_set<int> buffer;
    public:
    MyHashSet() {
        buffer.clear();
    }
    
    void add(int key) {
        buffer.insert(key);
    }
    
    void remove(int key) {
        buffer.erase(key);
    }
    
    bool contains(int key) {
        if(buffer.find(key) != buffer.end()) return true;
        return false;
    }
};

int main(){

}