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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == nullptr) return head;
        ListNode *temp=head;
        while(temp->next->next != nullptr){
            ListNode *newNode=new ListNode(__gcd(temp->val,temp->next->val),temp->next);
            temp->next=newNode;
            temp=temp->next->next;
        }
        ListNode *newNode=new ListNode(__gcd(temp->val,temp->next->val),temp->next);
        return head;
    }
};
int main(){
    Solution s;
    s.insertGreatestCommonDivisors(nullptr);
}