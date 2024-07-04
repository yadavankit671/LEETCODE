#include<bits/stdc++.h>
using namespace std;
class LFUCache {
private:
    struct Node {
        int key, value, freq;
        Node(int k, int v, int f) : key(k), value(v), freq(f) {}
    };

    int capacity, minFreq;
    unordered_map<int, list<Node>::iterator> keyNode;
    unordered_map<int, list<Node>> freqList;

    void updateFreqList(list<Node>::iterator it) {
        int key = it->key, value = it->value, freq = it->freq;
        freqList[freq].erase(it);
        if (freqList[freq].empty() && freq == minFreq) {
            minFreq++;
        }
        freqList[freq + 1].emplace_front(key, value, freq + 1);
        keyNode[key] = freqList[freq + 1].begin();
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}
    void print(){
        cout<<"\e[1m"<<"BUFFER :"<<"\e[0m"<<endl;
        for( auto x : keyNode) cout<<x.second->key<<"\t"<<x.second->value<<endl;
    }
    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) return -1;
        auto it = keyNode[key];
        int value = it->value;
        updateFreqList(it);
        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            auto it = keyNode[key];
            it->value = value;
            updateFreqList(it);
        } else {
            if (keyNode.size() == capacity) {
                auto it = freqList[minFreq].back();
                keyNode.erase(it.key);
                freqList[minFreq].pop_back();
            }
            freqList[1].emplace_front(key, value, 1);
            keyNode[key] = freqList[1].begin();
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(){
    LFUCache obj(2);
    obj.put(1,1);
    obj.print();
    obj.put(2,2);
    obj.print();
    cout<<"Get(1)-->"<<obj.get(1)<<endl;
    obj.put(3,3);
    obj.print();
    cout<<"Get(2)-->"<<obj.get(2)<<endl;
    cout<<"Get(3)-->"<<obj.get(3)<<endl;
    obj.put(4,4);
    obj.print();
    cout<<"Get(1)-->"<<obj.get(1)<<endl;
    cout<<"Get(3)-->"<<obj.get(3)<<endl;
    cout<<"Get(4)-->"<<obj.get(4)<<endl;
    obj.print();
}