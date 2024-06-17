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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l1=list1;
        ListNode* l2_head=list2;
        ListNode* l2_tail=list2;
        while(l2_tail->next){
            l2_tail=l2_tail->next;
        }
        int counter=0;
        while(counter<a-1) {
            //0-->1-->2-->3-->4-->5-->6-->7-->8-->9
            l1=l1->next;
            counter++;
        }
        ListNode* temp=l1;
        while(counter<=b){
            counter++;
            l1=l1->next;
        }
        l2_tail->next=l1;
        temp->next=l2_head;
        return list1;
    }
    void print(ListNode * node){
        if(node ==nullptr) {
            cout<<"Node is null"<<endl;
            return;
        } 
        cout<<"List:{"<<node->val;
        node=node->next;
        while(node){
            cout<<","<<node->val;
            node=node->next;
        }
        cout<<"}"<<endl;
    }
};
int main(){
    ListNode * list1=new ListNode(0,new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6,new ListNode(7,new ListNode(8,new ListNode(9,new ListNode(10,new ListNode(11))))))))))));
    ListNode * list2=new ListNode(20,new ListNode(30,new ListNode(40,new ListNode(50))));
    Solution obj;
    obj.print(obj.mergeInBetween(list1,3,5,list2));
}