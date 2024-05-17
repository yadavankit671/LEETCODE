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
    int solve(ListNode *node){
        if(!node) return 0;
        int carry=solve(node->next);
        int sum=node->val*2+carry;
        node->val=sum%10;
        carry=sum/10;
        return carry;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        int carry=solve(head);
        while(carry>0){
            head=new ListNode(carry%10,head);
            carry/=10;
        }
        return head;
    }
};
/*

class Solution {
    private:
    ListNode* reverseList(ListNode* head) {
        ListNode * temp=nullptr;
        while(head){
            ListNode* temp2=head->next;
            head->next=temp;
            temp=head;
            head=temp2;
        }
        return temp;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        if(!head) return head;
        head=reverseList(head);
        ListNode* result=nullptr;
        int carry=0;
        while(head){
            int sum=head->val*2+carry;
            result=new ListNode(sum%10,result);
            carry=sum/10;
            head=head->next;
        }
        while(carry>0){
            result=new ListNode(carry%10,result);
            carry=carry/10;
        }
        return result;
        /*
        If you want to save memory then reverse list first..
        save the head in a new variable 
        do the double operation 
        again reverse the list
        return the result;
        */
        /*
        If you want to optimize the algo
        use recursion to sovle 
        using recursion also sovles the space 
        dynamic approach..
        *//*
    }
};

*/
int main(){

}