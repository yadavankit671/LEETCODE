#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int getLength(ListNode* node){
        int len=0;
        while(node!=NULL){
            len++;
            node=node->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next==nullptr) return nullptr;
        n=getLength(head)-n;
        if(n==0) return head->next;
        ListNode* temp=head;
        while(n-1>0){
            n--;
            temp=temp->next;
        }
        if(temp->next==nullptr) return temp;
        temp->next=temp->next->next;
        return head;
    }
    void print(ListNode *head){
        if(head==nullptr) {cout<<"List is Empty"<<endl; return;}
        cout<<"Linked List : "<<head->val;
        head=head->next;
        while(head!=nullptr){
            cout<<"-->"<<head->val;
            head=head->next;
        }
        cout<<endl;
    }
};
int main(){
    ListNode *head=new ListNode(10);
    for(int i=9;i>=0;i--){
        head=new ListNode(i,head);
    }
    Solution s;
    s.print(head);
    head=s.removeNthFromEnd(head,11);
    s.print(head);
}