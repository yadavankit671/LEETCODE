#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=slow){
            if(fast==nullptr || fast->next==nullptr) return nullptr;
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=head;
        while(fast !=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};
int main(){

}