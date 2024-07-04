#include<bits/stdc++.h>
using namespace std;
class MyCircularQueue {
    private: 
    struct LinkedList{
        int val;
        LinkedList* next;
        LinkedList* prev;
        LinkedList() : val(0), next(nullptr), prev(nullptr) {}
        LinkedList(int val) : val(val), next(nullptr), prev(nullptr)  {}
        LinkedList(int val, LinkedList* next,LinkedList* prev) : val(val), next(next),prev(prev) {}
    };
    LinkedList* head;
    LinkedList* tail;
    int size;
    int capacity;
public:
    MyCircularQueue(int k) {
        head=nullptr;
        tail=nullptr;
        size=0;
        capacity=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            head=new LinkedList(value);
            tail=head;
            head->next=tail;
            tail->prev=head;
        }
        else{
            LinkedList *newNode = new LinkedList(value);
            newNode->next=head;
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
            head->prev=newNode;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(head==tail){
            delete head;
            head=tail=nullptr;
        }
        else{
            LinkedList* temp=head;
            head=head->next;
            head->prev=tail;
            tail->next=head;
            delete temp;
        }
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return head->val;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return capacity==size;
    }
};

int main(){

}