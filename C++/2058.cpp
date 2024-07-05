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
    vector<int> nodesBetweenCriticalPoints(ListNode* head){
        ios_base::sync_with_stdio(false); // can't afford to have low acceptance rate.
        int firstCritical=INT_MAX;
        int lastCritical=INT_MAX;
        int minDist=INT_MAX;
        int index=1;
        int prevValue=head->val;
        while(head){
            if(head->next && ((head->val>prevValue && head->val>head->next->val) || (head->val<prevValue && head->val<head->next->val))){
                if(firstCritical==INT_MAX) firstCritical=index;
                minDist=min(minDist,abs(index-lastCritical));
                lastCritical=index;
            }
            index++;
            prevValue=head->val;
            head=head->next;
        }
        vector<int> res={-1,-1};
        if(lastCritical==firstCritical) return res;
        res[1]=lastCritical-firstCritical;
        res[0]=min(minDist,res[1]);
        return res;
    }
};
int main(){

}