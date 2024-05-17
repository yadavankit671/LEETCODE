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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode * swapNode=nullptr;
        int count=1;
        ListNode * temp=head;
        while(temp ){
            if(count==k){
                swapNode=temp;
            }
            count++;
            temp=temp->next;
        }
        int count2=1;
        temp=head;
        while(temp){
            if(count-k==count2){
                swap(swapNode->val,temp->val);
                break;
            }
            count2++;
            temp=temp->next;
        }
        return head;
    }
    void print(ListNode* node){
        if(node==nullptr){
            cout<<"List is empty !!!"<<endl;
            return;
        }
        cout<<"List : {"<<node->val;
        node=node->next;
        while(node){
            cout<<","<<node->val;
            node=node->next;
        }
        cout<<"}"<<endl;
    }
    // K=3
    //1-->2-->3-->4-->5-->6-->7-->8-->9-->10-->11-->12
    //1-->2-->10-->4-->5-->6-->7-->8-->9-->3-->11-->12
};
int main(){
    ListNode *head=new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6,new ListNode(7,new ListNode(8,new ListNode(9,new ListNode(10,new ListNode(11,new ListNode(12))))))))))));
    Solution obj;
    obj.print(head);
    obj.swapNodes(head,6);
    obj.print(head);
}