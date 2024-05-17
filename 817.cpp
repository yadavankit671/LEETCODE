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
    int numComponents(ListNode* head, vector<int>& nums) {
        map<int,int> temp;
        int count = 0;
        int prev=-1;
        for(auto x: nums) temp[x]=1;
        while(head->next){
            if(temp[head->val] && temp[head->next->val]) count++;
            prev=head->val;
            head=head->next;
        }
        if(!temp[prev] && temp[head->val]) count++;
        return count;
    }
};
int main(){

}