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
    int len(ListNode *head){
        int ret=0;
        while(head){
            ret++;
            head=head->next;
        }
        return ret;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr) return nullptr;
        int length=len(head);
        length=length/2;
        ListNode *temp=head;
        while(length!=1){
            temp=temp->next;
            length--;
        }
        temp->next=temp->next->next;
        return head;
    }
};
int main(){

}