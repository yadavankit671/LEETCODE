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
    ListNode* middleNode(ListNode* head) {
        if(head->next==nullptr) return head;
        vector<ListNode* > vec;
        while(head!=nullptr){
            vec.push_back(head);
            head=head->next;
        }
        return vec[vec.size()/2];
    }
    void print(ListNode* list){
        if(list==nullptr){
            cout<<"List is Empty !!"<<endl;
            return;
        }
        cout<<"Linked List :"<<list->val;
        list=list->next;
        while(list !=nullptr){
            cout<<"-->"<<list->val;
            list=list->next;
        }
        cout<<endl;
    }
};
int main(){
    ListNode* list=nullptr;
    for(int i=5;i>=1;i--){
        list=new ListNode(i,list);
    }
    Solution obj;
    cout<<"Before :\n"<<endl;
    obj.print(list);
    list=obj.middleNode(list);
    cout<<"After :\n"<<endl;
    obj.print(list);
}