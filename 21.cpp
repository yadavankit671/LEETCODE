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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==nullptr )
        return list2;
        else if (list2==nullptr)
        return list1;
        ListNode *temp=new ListNode();
        ListNode *res=temp;
        bool flag=true;
        if (list1 == nullptr  || list2 == nullptr)
            flag=false;
        while(flag==true){
            if(list1->val < list2->val ){
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
            }
            else if(list2->val < list1->val ){
                temp->next=list2;
                temp=temp->next;
                list2=list2->next;
            }
            else  {
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
                temp->next=list2;
                temp=temp->next;
                list2=list2->next;
            }
            if (list1 == nullptr  || list2== nullptr)
            flag=false;
        }
        while(list1!=nullptr){
            temp->next=list1;
            temp=temp->next;
            list1=list1->next;
        }
        while(list2!=nullptr){
            temp->next=list2;
            temp=temp->next;
            list2=list2->next;
        }
        return res->next;
    }
};