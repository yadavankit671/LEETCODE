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
    int getLength(ListNode*node){
        if(node==nullptr) return 0;
        int len=1;
        while(node->next!=nullptr){
            len++;
            node=node->next;
        }
        return len;
    }
    ListNode* rotate(ListNode *node){
        if(node==nullptr || node->next==nullptr){
            return nullptr;
        }
        ListNode* temp=node;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        node=new ListNode(temp->val,node);
        temp=node;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        temp->next=nullptr;
        return node;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0 || head->next==nullptr) return head;
        ListNode* temp=head;
        int len=getLength(head);
        k=k%len;
        cout<<k<<endl;
        for(int i=0; i<k; i++){
            temp=rotate(temp);
        }
        return temp;
    }
    void print(ListNode* node) {
        if(node==nullptr){
            cout<<"List is null!"<<endl;
            return ;
        }
        cout<<"List : "<<node->val;
        node=node->next;
        while(node!=nullptr){
            cout<<"-->"<<node->val;
            node=node->next;
        }
        cout<<endl<<endl;
    }
};
int main(){
    ListNode* head=nullptr;
    for(int i=500;i>0;i--){
        head=new ListNode(i,head);
    }

    Solution s;
    s.print(head);
    head=s.rotateRight(head,2000000);
    s.print(head);
}