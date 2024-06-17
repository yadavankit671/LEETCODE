#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
class Solution {
public:

    void merge(Node* here){
        if(here->next==nullptr && here->child!=nullptr){
            here->child->prev=here;
            here->next=here->child;
            here->child=nullptr;
        }
        else{
            Node* temp=here->next;
            here->child->prev=here;
            here->next=here->child;
            here->child=nullptr;
            while(here->next!=nullptr){
                here=here->next;
            }
            temp->prev=here;
            here->next=temp;
        }
    }
    Node* flatten(Node* head) {
        if (head==nullptr) return nullptr;
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->child!=nullptr){
                merge(temp);
            }
            else temp=temp->next;
        }
        return head;
    }
};
int main(){

}