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
    vector<ListNode *> nodes;
    public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr)return head;
        ListNode *temp=head;
        while(temp){
            nodes.push_back(temp);
            temp=temp->next;
        }
        sort(nodes.begin(),nodes.end(),[](ListNode *a,ListNode *b){return a->val<b->val;});
        head=nodes[0];
        head->next=nullptr;
        temp=head;
        for(int i=1;i<nodes.size();i++){
            temp->next=nodes[i];
            temp=temp->next;
        }
        temp->next=nullptr;
        return head;
    }
    void print(){
        if(nodes.size()==0 ){
            cout<<"List is Empty "<<endl;
            return;
        }
        cout<<"List :{"<<nodes[0]->val;
        for(int i=1;i<nodes.size();i++){
            cout<<","<<nodes[i]->val;
        }
        cout<<"}";
    }
    void print(ListNode* node){
        if(node==nullptr){
            cout<<"List is Empty "<<endl;
            return;
        }
        cout<<"List :{"<<node->val;
        node=node->next;
        while(node){
            cout<<","<<node->val;
            node=node->next;
        }
        cout<<"}"<<endl;
    }
};

int main(){
    ListNode * list1=new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(1))));
    Solution obj;
    list1=obj.sortList(list1);
    obj.print(list1);
}