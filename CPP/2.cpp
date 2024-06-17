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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res= new ListNode(sizeof(ListNode));
        ListNode *temp= res;
        int carry=0;
        // 5-4-9   5-5
        while(l1!=NULL || l2!=NULL){
            int num1=(l1!=NULL)? l1->val : 0;
            int num2=(l2!=NULL)? l2->val : 0;
            int sum=num1+num2+carry;
            carry=(sum>9)? 1:0;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            if(l1!=NULL)
            l1=l1->next;
            if(l2!=NULL)
            l2=l2->next;
            if (carry>0)
            temp->next= new ListNode(1);
        }
        return res->next;
    }
};
int main(){

}