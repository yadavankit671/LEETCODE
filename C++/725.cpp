#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print(ListNode* node){
    if(node==nullptr) {
        cout<<"Empty List"<<endl;
        return;
    }
    cout<<"\nList : "<<node->val;
    node=node->next;
    while(node){
        cout<<"-->"<<node->val;
        node=node->next;
    }
    cout<<endl;
}
void print(vector<ListNode *> list){
    if(list.size()==0) {
        cout<<"Empty List"<<endl;
        return;
    }
    cout<<"Result : "<<endl;
    for(int i=0; i<list.size(); i++){
        cout<<endl<<i+1<<" :";
        print(list[i]);
    }
    cout<<endl;
}
class Solution {
    private:
    int getLength(ListNode *head){
        int counter=0;
        while(head){
            counter++;
            head=head->next;
        }
        return counter;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=getLength(head);
        int parts=(n/k>0)?n/k:1; // 10/3=3
        int rem=n-(parts*k);
        ListNode* next=head;
        vector<ListNode *> result(k,nullptr);
        int i=0;
        while(k>0){
            if(head==nullptr) break;
            result[i++]=next;
            int temp=parts;
            while(temp>1){
                if(head==nullptr) return result;
                head=head->next;
                temp--;
            }
            if(rem>0){head=head->next;rem--;}
            next=head->next;
            head->next=nullptr; // for this portion you have next mainly..
            head=next;
            k--;
        }
        return result;
    }
};
int main(){
    ListNode* head=nullptr;
    for(int i=19;i>0;i--) head=new ListNode(i,head); 
    Solution obj;
    int k=50;
    vector<ListNode *> result=obj.splitListToParts(head,k);
    print(result);
}