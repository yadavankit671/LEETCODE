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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        if(root->left==nullptr && root->right==nullptr) return vector<int>(1,root->val);
        vector<int>result;
        traversal(result,root);
        return result;
    }
    private:
    void traversal(vector<int>&result,TreeNode* root){
        if(root==nullptr) return;
        traversal(result,root->left);
        traversal(result,root->right);
        result.push_back(root->val);
    }
};
int main(){

}