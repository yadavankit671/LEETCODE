#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    // 2--> or &&  3--> and  && 0-> false && 1-> true
    private:
    bool result(int x,int y,int op){
        if(op==2) {
            if(x==0 && y==0) return false;
            return true;
        }
        if(x==1 && y==1) return true;
        return false;
    }
    bool traversal(TreeNode * node){
        if(node->left && node->right && node->left->val<2 && node->right->val<2){
            return result(node->left->val,node->right->val,node->val);
        }
        else if(node->left && node->left->val<2){
            bool right = traversal(node->right);
            return result(node->left->val,right,node->val);
        }
        else if(node->right && node->right->val<2){
            bool left = traversal(node->left);
            return result(left,node->right->val,node->val);
        }
        bool left=traversal(node->left);
        bool right=traversal(node->right);
        return result(left,right,node->val);
    }
    public:
    bool evaluateTree(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        return traversal(root);
    }
};
int main(char* args){

}