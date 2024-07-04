#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    private:
    bool check(TreeNode *node, ListNode *curr){
        if(curr==nullptr) return true;
        if(node==nullptr || curr==nullptr) return false;
        if(node->val!=curr->val) return false;
        return check(node->left,curr->next) | check(node->right,curr->next);
    }
    bool traversal(TreeNode *node, ListNode *head){
        if(node==nullptr) return false;
        if(node->val==head->val){
            if(check(node,head)) return true;
        }
        return traversal(node->left,head) | traversal(node->right,head);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return traversal(root,head);
    }
};
int main(){

}