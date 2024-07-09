#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node * next;
    Node(int v){
        val=v;
        next=nullptr;
    }
};
class Solution {
    private : 
    Node *head;
    Node *tail;
    void initialize(int n){
        head=new Node(-1);
        Node *prev=head;
        for(int i=1;i<=n;i++){
            Node *temp=new Node(i);
            prev->next=temp;
            prev=temp;
        }
        head=head->next;
        prev->next=head;
        tail=prev;
    }
    int solve(int n,int k){
        if(k==1) return tail->val;
        Node *start=head;
        Node *prev=nullptr;
        while(n!=1){
            int t=k-1;
            while(t--){
                prev=start;
                start=start->next;
            }
            if(start->next==head){
                prev->next=head;
                start=head;
            }
            else if(start==head){
                start=head->next;
                prev->next=head->next;
                head=head->next;
            }
            else{
                start=start->next;
                prev->next=start;
            }
            n--;
        }
        return start->val;
    }
    public :
    int findTheWinner(int n, int k) {
        initialize(n);
        return solve(n,k);
    }
};
int main(){

}