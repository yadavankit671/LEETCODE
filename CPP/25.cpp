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
    vector<int> buffer;
    void loadbuffer(ListNode*node,int k){
        while(node!=NULL){
            buffer.push_back(node->val);
            node=node->next;
        }
        for(int i=0;i<buffer.size();i+=k){
            if(i+k>buffer.size())break;
            reverse(buffer.begin()+i,buffer.begin()+i+k);
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || head==nullptr) return head;
        ListNode* result=new ListNode(0,head);
        loadbuffer(head,k);
        int i=0;
        while(head!=nullptr){
            head->val=buffer[i];
            head=head->next;
            i++;
        }
        return result->next;
    }
    void print(ListNode* list){
        if(list==nullptr){
            cout<<"list is empty !!";
            return;
        }
        cout<<"List  :"<<list->val;
        list=list->next;
        while(list!=nullptr){
            cout<<" -> "<<list->val;
            list=list->next;
        }
        cout<<endl;
    }
};
int main(){
    ListNode* sender=nullptr;
    for(int i=10;i>0;i--){
        sender=new ListNode(i,sender);
    }
    Solution obj;
    obj.print(sender);
    obj.reverseKGroup(sender,4);
    obj.print(sender);
}