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
    ListNode* reverse(ListNode* node, int limit){
        if(node == nullptr) return nullptr;
        ListNode * temp=nullptr;
        while(limit!=0){
            limit--;
            temp=new ListNode(node->val,temp);
            node=node->next;
            if(node==nullptr) break;
        }
        ListNode* result=temp;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=node;
        return result;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right || head->next==nullptr) return head;
        if(head->next->next==nullptr){
            head=new ListNode(head->next->val,head);
            head->next->next=nullptr;
            return head;
        }
        int no_of_nodes_to_be_reversed=right-left+1;
        ListNode* temp=new ListNode();
        ListNode* result=temp;
        while(left!=1){
            left--;
            temp->next=new ListNode(head->val);
            temp=temp->next;
            head=head->next;
        }
        temp->next=reverse(head,no_of_nodes_to_be_reversed);
        return result->next;
    }
    void print(ListNode* list){
        if(list==nullptr){
            cout<<"List is Empty !!"<<endl;
            return;
        }
        cout<<"Linked List :"<<list->val;
        list=list->next;
        while(list !=nullptr){
            cout<<"-->"<<list->val;
            list=list->next;
        }
        cout<<endl;
    }
};
int main(){
    ListNode* list=nullptr;
    for(int i=5;i>=1;i--){
        list=new ListNode(i,list);
    }
    Solution obj;
    cout<<"Before :\n"<<endl;
    obj.print(list);
    list=obj.reverseBetween(list,2,4);
    cout<<"After :\n"<<endl;
    obj.print(list);
}