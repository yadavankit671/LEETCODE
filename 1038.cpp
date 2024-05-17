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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        traversal(root,sum);
        return root;
    }
    void traversal(TreeNode *root,int &sum){
        if(root==nullptr) return;
        traversal(root->right,sum);
        root->val+=sum;
        sum=root->val;
        traversal(root->left,sum);
    }
};
int main(){

}