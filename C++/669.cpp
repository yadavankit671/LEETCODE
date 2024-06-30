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
    private:
    TreeNode* solve (TreeNode *node,int low,int high){
        if(node==nullptr) return nullptr;
        if(node->val<low) node=solve(node->right,low,high);
        else if(node->val>high) node=solve(node->left,low,high);
        else {
            node->left=solve(node->left,low,high);
            node->right=solve(node->right,low,high);
        }
        return node;
    }
    public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        root=solve(root,low,high);
        return root;
    }
};
int main(){

}