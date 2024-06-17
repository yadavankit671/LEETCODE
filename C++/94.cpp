#include<bits/stdc++.h>
using namespace std;

  //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root ==nullptr) return result;
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
        return result;
    }
};
int main(){
    Solution s;
    TreeNode *root = new TreeNode();
    s.inorderTraversal(root);
}

//[1,2,3,5,4,9,11]