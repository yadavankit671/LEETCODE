#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    //                  4---> 5 ----> 6 ----> 7 ----> 8
class Solution {
public:
    void swap(ListNode *node1,ListNode *node2) {
        int temp=node1->val;
        node1->val=node2->val;
        node2->val=temp;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode *temp=head;
        while(temp->next!=nullptr){
            temp->val+=temp->next->val;
            temp->next->val=temp->val-temp->next->val;
            temp->val=temp->val-temp->next->val;
            temp=temp->next;
            if(temp->next!=nullptr)
            temp=temp->next;
        }
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
    Solution obj;
    obj.print(head);
    head=obj.swapPairs(head);
    obj.print(head);
}