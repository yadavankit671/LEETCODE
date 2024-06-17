#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val):val(val), next(nullptr){}
    Node(int val, Node* next):val(val), next(next) {}
};
class MyLinkedList {
public:
    Node* head;
    MyLinkedList() {
        this->head=nullptr;
    }
    void insertion(int val){
        if(this->head==nullptr){
            head=new Node(val);
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=new Node(val);
    }
    int get(int index) {
        int length=this->getLength();
        if(index<0 || index>=length){
            return -1;
        }
        Node*temp=this->head;
        int count=0;
        while(count<index){
            count++;
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        if(this->head==nullptr){
            this->head=new Node(val);
            return;
        }
        this->head=new Node(val,this->head);
    }
    
    void addAtTail(int val) {
        if(this->head==nullptr){
            this->head=new Node(val);
            return;
        }
        Node*temp=this->head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=new Node(val);
    }
    
    void addAtIndex(int index, int val) {
        int length=this->getLength();
        if(index>length || (index >0 &&this->head==nullptr)){
            return;
        }
        if(index==0){
            this->addAtHead(val);
            return;
        }
        if(index==length){
            this->addAtTail(val);
            return;
        }
        Node* temp=this->head;
        int count=0;
        while(count<index-1){
            temp=temp->next;
            count++;
            if(temp->next==nullptr){
                return;
            }
        }
        Node* newNode =new Node(val,temp->next);
        temp->next=newNode;
    }
    
    void deleteAtIndex(int index) {
        if(head==nullptr) return;
        if(index==0) {
            this->head=this->head->next;
            return;
        }
        int length=this->getLength();
        if(index>=length){
            return;
        }
        Node* temp=this->head;
        int count=0;
        while(count<index-1){
            temp=temp->next;
            count++;
            if(temp->next==nullptr){
                return;
            }
        }
        temp->next=temp->next->next;
    }
    int getLength(){
        if(this->head==nullptr){
            return 0;
        }
        Node* temp=this->head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        return count;
    }
    void print(){
        if(this->head==nullptr){
            cout<<"Empty list !!"<<endl;
            return;
        }
        Node* temp=this->head;
        cout<<"List : "<<temp->val;
        temp=temp->next;
        while(temp!=nullptr){
            cout<<"-->"<<temp->val;
            temp=temp->next;
        }
        cout<<endl;
    }
    void clearList(){
        this->head=nullptr;
    }
};
int main(){
    MyLinkedList *obj=new MyLinkedList();
    for(int i=3;i<10;i++){
        obj->insertion(i);
    }
    obj->print();
    obj->clearList();
    obj->print();
    //["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]
    //[[],                [0,10],     [0,20],     [1,30],     [0]]
    obj->addAtIndex(0,10);
    obj->addAtIndex(0,20);
    obj->addAtIndex(1,30);
    obj->print();
    cout<<obj->get(0);
}