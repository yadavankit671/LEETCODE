#include<bits/stdc++.h>
using namespace std;
class MyHashMap {
    private:
    unordered_map<int,int> buffer;
    public:
    MyHashMap() {
        buffer.clear();
    }
    void put(int key, int value) {
        buffer[key] = value;
    }
    
    int get(int key) {
        if(buffer.find(key)==buffer.end()) return -1;
        return buffer[key];
    }
    
    void remove(int key) {
        buffer.erase(key);
    }
};
int main(){

}