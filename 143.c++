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
    void reorderList(ListNode* head) {
        if(head==nullptr) return;
        if(head->next==nullptr) return;
        if(head->next->next==nullptr) return;
        vector<ListNode *> buffer;
        ListNode *temp=head;
        while(temp!=nullptr){
            buffer.push_back(temp);
            temp=temp->next;
        }
        temp=head;
        int len=buffer.size();
        while(buffer.size()!=len/2){
            buffer[buffer.size()-1]->next=temp->next;
            temp->next=buffer[buffer.size()-1];
            cout<<temp->val<<"          "<<buffer[buffer.size()-1]->val<<endl;
            buffer.pop_back();
            temp=temp->next;
            temp=temp->next;
        }
        temp->next=nullptr;
    }
};
void print(ListNode *head){
        cout<<"List :";
        ListNode *temp=head;
        while(temp!=nullptr){
            cout<<" "<<temp->val;
            temp=temp->next;
        }
        cout<<endl;
    }
int main(){
    ListNode *head;
    for(int i=9;i>=1;i--) head=new ListNode(i,head);
    Solution obj;
    obj.reorderList(head);
    print(head);
}