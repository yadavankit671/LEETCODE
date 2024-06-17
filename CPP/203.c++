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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;
        ListNode* result=new ListNode();
        ListNode* temp=result;
        while(head != nullptr){
            if(head->val != val){
                temp->next=new ListNode(head->val);
                temp=temp->next;
            }
            head=head->next;
        }
        return result->next;
    }
};
int main(){

}