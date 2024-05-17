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
    vector<int> buffer;
    public:
    Solution(ListNode* head) {
        while(head){
            buffer.push_back(head->val);
        }
    }
    int getRandom() {
        int random=rand()%buffer.size();
        return buffer[random];
    }
};
int main(){

}