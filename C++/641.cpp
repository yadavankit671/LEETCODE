#include<bits/stdc++.h>
using namespace std;
class MyCircularDeque {
    private : 
    int size;
    struct Node{
        int data;
        Node *next;
        Node *prev;
        Node(int data) : data(data), next(nullptr), prev(nullptr) {};
    };
    int curr;
    Node *head;
    Node *tail;
public:
    MyCircularDeque(int k) {
        this->size = k;
        this->curr = 0;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    bool insertFront(int value) {
        if(curr == size) return false;
        Node *newNode = new Node(value);
        newNode->next = head->next;
        head->next->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
        curr++;
        return true;
    }
    
    bool insertLast(int value) {
        if(curr == size) return false;
        Node * newNode = new Node(value);
        newNode->next = tail;
        newNode->prev = tail->prev;
        tail->prev->next = newNode;
        tail->prev = newNode;
        curr++;
        return true;
    }
    
    bool deleteFront() {
        if(curr == 0 || head == tail) return false;
        curr--;
        Node *temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        delete temp;
        return true;
    }
    
    bool deleteLast() {
        if(curr == 0 || head == tail) return false;
        curr--;
        Node *temp = tail->prev;
        tail->prev = temp->prev;
        temp->prev->next = tail;
        delete temp;
        return true;
    }
    
    int getFront() {
        return head->next->data;
    }
    
    int getRear() {
        return tail->prev->data;
    }
    
    bool isEmpty() {
        return curr == 0;
    }
    
    bool isFull() {
        return curr == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
int main(){

}