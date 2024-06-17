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
    int pairSum(ListNode* head) {
        int res=INT_MIN;
        vector<int> buffer;
        while(head){
            buffer.push_back(head->val);
            head = head->next;
        }
        for(int i=0;i<buffer.size()/2;i++) res=max(res,buffer.at(i)+buffer.at(buffer.size()-1-i));
        return res;
    }
};
int main(){
    ListNode *head=new ListNode(4,new ListNode(2,new ListNode(2,new ListNode(3))));
    Solution obj;
    cout<<obj.pairSum(head);
}