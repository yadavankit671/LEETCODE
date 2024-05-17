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
    int getlength(ListNode* node){
        int count=0;
        while(node!=NULL){
            count++;
            node=node->next;
        }
        return count;
    }
    int getDecimalValue(ListNode* head) {
        int result=0;
        int len=getlength(head)-1;
        while(head!=nullptr){
            result=result+head->val*pow(2,len--);
            head=head->next;
        }
        return result;
    }
};
int main(){
    ListNode *head=new ListNode(1,new ListNode(0,new ListNode(0)));
    Solution obj;
    cout<<obj.getDecimalValue(head);

}
