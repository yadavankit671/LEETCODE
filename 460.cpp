#include<bits/stdc++.h>
using namespace std;
/*

NOT FINISHED

*/
struct Node {
    int data;
    int key;
    Node *next;
    Node *prev;
    Node(): data(-1),key(-1),next(nullptr),prev(nullptr){}
    Node(int data,int key): data(data),key(key),next(nullptr),prev(nullptr){}
    Node(int data,int key,Node *next,Node *prev): data(data),key(key),next(next),prev(prev){}
};
class LFUCache {
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
    void print(){
        cout<<"\e[1m"<<"BUFFER :"<<"\e[0m"<<endl;
        for( auto x : list) cout<<x.second->key<<"\t"<<x.second->data<<endl;
    }
    LFUCache(int capacity) {
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