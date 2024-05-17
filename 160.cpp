#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    private:
    int getLengh(ListNode *node){
        if(node==nullptr) return 0;
        int counter =0;
        while(node){
            counter++;
            node = node->next;
        }
        return counter;
    }
public:
/*
Logic --> its intersection meaning that both list will converge to one list 
        i.e., both list will end at the same node
        headA = 1->2->3->4->5->6->7->8
        headB =      14->4->5->6->7->8
        we find the difference of length because after the extra part both lists will continue linearly and converge at a point
*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=getLengh(headA);
        int l2=getLengh(headB);
        ListNode * largest =nullptr;
        ListNode * smallest =nullptr;
        int dif=0;
        if(l1>=l2){
            largest=headA;
            smallest =headB;
            dif=l1-l2;
        }
        else {
            largest=headB;
            smallest=headA;
            dif=l2-l1;
        }
        while(dif>0){
            largest=largest->next;
            dif--;
        }
        while(largest!=nullptr){
            if(largest==smallest){
                return largest;
            }
            largest=largest->next;
            smallest=smallest->next;
        }
        return nullptr;
    }
};
int main(){

}