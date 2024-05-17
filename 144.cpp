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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        if(root->left == nullptr && root->right==nullptr) return vector<int>(1,root->val);
        vector<int> result;
        preorder(result,root);
        return result;
    }
    private:
    void preorder(vector<int>&result,TreeNode*root){
        if(root ==nullptr) return;
        result.push_back(root->val);
        preorder(result,root->left);
        preorder(result,root->right);
    }
};
int main(){

}