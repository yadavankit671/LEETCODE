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
vector<int>reject;
    void rejected(ListNode* node){
        while(node->next!=nullptr){
            if(node->val==node->next->val){
                reject.push_back(node->val);
            }
            node=node->next;
        }
    }
    bool check(int val){
        for(int i=0; i<reject.size(); i++){
            if(val==reject.at(i)){
                return false;
            }
        }
        return true;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode* res=new ListNode();
        ListNode* temp=res;
        rejected(head);
        while(head!=nullptr){
            auto i=find(reject.begin(),reject.end(),head->val);
            if(i==reject.end()){
                cout<<endl;
                temp->next=new ListNode(head->val);
                temp=temp->next;
            }
            head=head->next;
        }
        return res->next;
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
    ListNode *head=nullptr;
    head=new ListNode(5,head);
    head=new ListNode(5,head);
    head=new ListNode(3,head);
    head=new ListNode(2,head);
    head=new ListNode(1,head);
    head=new ListNode(0,head);
    Solution s;
    s.print(head);
    head=s.deleteDuplicates(head);
    s.print(head);
}
