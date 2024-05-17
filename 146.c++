#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    int key;
    Node *next;
    Node *prev;
    Node(): data(-1),key(-1),next(nullptr),prev(nullptr){}
    Node(int data,int key): data(data),key(key),next(nullptr),prev(nullptr){}
};
class LRUCache {
    private:
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int,Node*> list;
    // Private functions ::

    void addNode(Node *new_node){
        Node *temp=head->next;
        head->next=new_node;
        new_node->next=temp;
        temp->prev=new_node;
        new_node->prev=head;
    }
    void deleteNode(Node *delNode){
        Node *prevNode=delNode->prev;
        Node *nextNode=delNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
    }
    int get(int key) {
        if(list.find(key)!=list.end()){
            Node *flushNode=list[key];
            deleteNode(flushNode);
            addNode(flushNode);
            list[key]=head->next;
            return head->next->data;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(list.find(key)==list.end()){
            if(list.size()==capacity){
                list.erase(tail->prev->key);
                deleteNode(tail->prev);
                addNode(new Node(value,key));
                list[key]=head->next;
            }
            else {
                addNode(new Node(value,key));
                list[key]=head->next;
            }
        }
        else{
            Node *delNode =list[key];
            deleteNode(delNode);
            delNode->data = value;
            addNode(delNode);
            list[key]=head->next;
        }
    }
};
/*
["LRUCache", "put",   "put", "get", "put", "get", "put", "get", "get", "get"]
[[2],        [1, 1], [2, 2],  [1],  [3, 3], [2],  [4, 4],  [1],   [3], [4]]
*/
int main(){
    LRUCache obj(2);
    obj.put(1,1);
    obj.put(2,2);
    cout<<obj.get(1);
    obj.put(3,3);
    cout<<obj.get(3);
    obj.put(4,4);
    cout<<obj.get(1);
    cout<<obj.get(3);
    cout<<obj.get(4);
}
