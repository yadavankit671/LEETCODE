#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// class Solution {
// public:
//     bool check(ListNode *list1, ListNode *list2){
//         while(list1!= nullptr && list2!= nullptr){
//             if(list1->val!= list2->val){
//                 return false;
//             }
//             list1 = list1->next;
//             list2 = list2->next;
//         }
//         return true;
//     }
//     bool isPalindrome(ListNode* head) {
//         if(head->next==nullptr) return true;
//         ListNode* list=nullptr;
//         ListNode*temp=head;
//         while(temp!=nullptr){
//             list=new ListNode(temp->val,list);
//             temp=temp->next;
//         }
//         return check(list,head);
//     }
// };
// This approach was used so that O(1) space is used .. made it little time consuming still order of n but
//  len->n  +   travel to half node-->n/2   + rev->n/2   + check->n/2   == (5/2)n

// if space complexity would not have been an issue we could have used a string and checked for palindrome !!
// making a string-->n  + check->n/2 == (3/2)n  significantly faster than before

class Solution {
    private:
    int length(ListNode* node){
        if(node==nullptr) return 0;
        int count=0;
        while(node){
            count++;
            node=node->next;
        }
        return count;
    }
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
    bool isPalindrome(ListNode* head) {
        int len=length(head);
        ListNode* temp=head;
        int  half=ceil(float(len)/2);
        int count=0;
        while(count<half){
            temp=temp->next;
            count++;
        }
        temp=reverseList(temp);
        while(temp){
            if(temp->val!=head->val) return false;
            temp=temp->next;
            head=head->next;
        }
        return true;
    }
};
int main(){
    ListNode* head=new ListNode(1,(new ListNode(4,(new ListNode(9,(new ListNode(4,new ListNode(1))))))));
    Solution obj;
    if(obj.isPalindrome(head)) cout<<"Palindrome";
    else cout<<"Not Palindrome";
}