#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    //1-->2-->3-->4-->5
    void deleteNode(ListNode* node) {
        while(node->next->next){
            node->val=node->next->val;
            node=node->next;
        }
        node->val=node->next->val;
        node->next=NULL;
    }
    void print(ListNode *node) {
        if(!node){
            cout<<"List Empty !!";
            return;
        }
        cout<<"\nList :{"<<node->val;
        node=node->next;
        while(node){
            cout<<","<<node->val;
            node=node->next;
        }
        cout<<"}";
    }
};
int main(){
    ListNode* head=new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    Solution s;
    s.deleteNode(head->next);
    s.print(head);
}