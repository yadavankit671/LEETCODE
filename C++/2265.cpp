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
    int averageOfSubtree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return 1;
        int counter=0;
        traversal(root,counter);
        return counter;
    }
    private:
    void traversal(TreeNode *root,int &counter) {
        if(root == nullptr)return;
        vector<int> buffer;
        inorder(root,buffer);
        int add=accumulate(buffer.begin(),buffer.end(),0);
        if(add/buffer.size()==root->val) counter++;
        traversal(root->left,counter);
        traversal(root->right,counter);
    }
    void inorder (TreeNode* node,vector<int>& buffer) {
        if(node == nullptr)return;
        buffer.push_back(node->val);
        inorder(node->left,buffer);
        inorder(node->right,buffer);
    }
};
int main(){

}