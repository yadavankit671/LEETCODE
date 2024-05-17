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
    int solve(TreeNode *node,int target){
        if(node==nullptr) return 0;
        if(node->left && node->left->val==target && !node->left->left && !node->left->right) node->left=nullptr;
        if(node->right && node->right->val==target && !node->right->left && !node->right->right) node->right=nullptr;
        int left=solve(node->left,target);
        int right=solve(node->right,target);
        return left+right+1;
    }
    public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        int totalNodes=INT_MAX;
        int newCount=0;
        while(totalNodes!=newCount){
            totalNodes=newCount;
            newCount=solve(root,target);
        }
        if(!root->left && !root->right && root->val==target) return nullptr;
        return root;
    }
};
int main(char* args){

}