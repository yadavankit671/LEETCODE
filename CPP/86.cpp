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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode *res=new ListNode(0);
        ListNode *left=res;
        ListNode *temp=new ListNode(0);
        ListNode *right=temp;
        while(head!=nullptr){
            if(head->val<x){
                left->next=new ListNode(head->val);
                left=left->next;
            }
            else{
                right->next=new ListNode(head->val);
                right=right->next;
            }
            head=head->next;
        }
        left->next=temp->next;
        return res->next;
    }
    void print(ListNode *node){
        if(node==nullptr){
            cout<<"List Empty !!"<<endl;
            return;
        }
        cout<<"List : ";
        while(node){
            cout<<node->val<<",";
            node=node->next;
        }
        cout<<endl;
    }
};
//[1,4,3,2,5,2]
int main(){
    ListNode *head=new ListNode(1,new ListNode(4,new ListNode(3,new ListNode(2,new ListNode(5,new ListNode(2))))));
    int x=3;
    Solution s;
    head=s.partition(head,x);
    s.print(head);
}