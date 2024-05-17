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
    ListNode* reverseList(ListNode* head) {
        ListNode * temp=nullptr;
        while(head){
            ListNode* temp2=head->next;
            head->next=temp;
            temp=head;
            head=temp2;
        }
        return temp;
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
    head=s.reverseList(head);
    s.print(head);
}
/*

if (head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode* result=new ListNode(head->val,nullptr);
        head=head->next;
        while(head !=nullptr){
            result=new ListNode(head->val,result);
            head=head->next;
        }
        return result;

*/