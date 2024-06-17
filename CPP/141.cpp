#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(0);
        if(head==nullptr) return false;
        if(head->next==nullptr) return false;
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=nullptr && slow!=nullptr){
            if(fast==nullptr) return false;
            fast=fast->next;
            if(fast==nullptr) return false;
            fast=fast->next;
            if(slow==nullptr) return false;
            slow=slow->next;
            if(slow==nullptr || fast==nullptr) return false;
            if(fast==slow && fast!=nullptr) return true;
        }
        return false;
    }
};
int main(){
    Solution s;
    ListNode *head=new ListNode(4);
    ListNode *body=new ListNode(5);
    ListNode *tail=new ListNode(6);
    head->next=body;
    body->next=tail;
    tail->next=body;
    cout<<s.hasCycle(head);
}

