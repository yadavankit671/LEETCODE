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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        vector<int> list;int i=1;
        for(ListNode* it = lists[0]; i<=lists.size();it=lists[i++]){
            while(it != nullptr){
                list.push_back(it->val);
                it = it->next;
            }
        }
        if(list.size()==0) return nullptr;
        sort(list.begin(),list.end());
        ListNode *head=new ListNode(list[0]);
        ListNode* result=head;
        for(int i=1;i<list.size();i++){
            head->next=new ListNode(list[i]);
            head=head->next;
        }
        return result;
    }
};
int main(){
    // code likhne mein aalas aaraha basically 3-4 list banao aur usko vector list mein daalo
}