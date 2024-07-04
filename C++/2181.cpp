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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode *temp= new ListNode(0);
        ListNode *result=temp;
        while(head!=nullptr){
            sum+=head->val;
            if(head->val==0 && sum>0){
                temp->next=new ListNode(sum);
                temp=temp->next;
                sum=0;
            }
            head=head->next;
        }
        return result->next;
    }
};
int main(){

}