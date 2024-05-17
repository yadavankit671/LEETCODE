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
    private:
    vector<ListNode*> nodes_odd;
    vector<ListNode*> nodes_even;
    public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode * odd=head;
        ListNode* even=head->next;
        ListNode* temp=even->next;
        ListNode* evenJoin =even;
        while(temp){
            odd->next=temp;
            odd=odd->next;
            temp=temp->next;
            if(!temp)break;
            even->next=temp;
            even=even->next;
            temp=temp->next;
        }
        even->next=nullptr;
        odd->next=evenJoin;
        return head;
    }
    void print(ListNode *node){
        if (node ==nullptr){
            cout<<"List is empty !!"<<endl;
            return;
        }
        cout<<"List :{"<<node->val;
        node=node->next;
        while(node){
            cout<<","<<node->val;
            node=node->next;
        }
        cout<<"}"<<endl;
    }
};
int main(){
    // 1-->3-->5-->2-->4
    ListNode * list1=new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6,new ListNode(7,new ListNode(8,new ListNode(9,new ListNode(10,new ListNode(11)))))))))));
    Solution obj;
    list1=obj.oddEvenList(list1);
    obj.print(list1);
}