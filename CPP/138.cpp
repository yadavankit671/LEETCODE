#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        Node* result=new Node(INT_MIN);
        Node* res=result;
        Node* temp=head;
        int node_len=find_length(temp);
        while(temp!=nullptr){
            result->next=new Node(temp->val);
            temp=temp->next;
            result=result->next;
        }
        temp=head;result=res;result=result->next;
        while(temp!=nullptr){
            if(temp->random!=nullptr){
                int len=find_length(temp->random);
                result->random=findNode(res->next,node_len-len);
            }
            result=result->next;
            temp=temp->next;
        }
        return res->next;
    }
    Node* findNode(Node* head,int length){
        Node* temp=head;
        int len=0;
        while(temp!=nullptr){
            if(len==length) return temp;
            temp=temp->next;
            len++;
        }
        return nullptr;
    }
    int find_length(Node* head){
        int length=0;
        Node* temp=head;
        while(temp!=nullptr){
            length++;
            temp=temp->next;
        }
        return length;
    }
};
int main(){
    Node* head= new Node(3);
    Node* b=new Node(5);head->next=b;
    Node* c=new Node(4);b->next=c;
    Node* d=new Node(-9);c->next=d;
    Node* e=new Node(-10);d->next=e;
    Node* f=new Node(5);e->next=f;
    Node* g=new Node(0);f->next=g;
    Node* h=new Node(6);g->next=h;
    Node* i=new Node(-6);h->next=i;
    Node* j=new Node(3);i->next=j;
    Node* k=new Node(-6);j->next=k;
    Node* l=new Node(9);k->next=l;
    Node* m=new Node(-2);l->next=m;
    Node* n=new Node(-3);m->next=n;
    Node* o=new Node(-1);n->next=o;
    Node* p=new Node(2);o->next=p;
    Node* q=new Node(-3);p->next=q;
    Node* r=new Node(-9);q->next=r;
    Node* s=new Node(-2);r->next=s;
    Node* t=new Node(-8);s->next=t;
    Node* u=new Node(5);t->next=u;
}