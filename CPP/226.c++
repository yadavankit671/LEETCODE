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
    TreeNode* invertTree(TreeNode* root) {
        if (root ==nullptr)return nullptr;
        if(root->left==nullptr && root->right==nullptr)return root;
        Swapping(root);
        return root;
    }
    void Swapping(TreeNode* root){
        if(root==nullptr)return;
        if(root->left==nullptr && root->right==nullptr)return;
        else if(root->left!=nullptr && root->right!=nullptr){
            TreeNode* temp1=root->left;
            TreeNode* temp2=root->right;
            root->left=temp2;
            root->right=temp1;
            Swapping(root->left);
            Swapping(root->right);
        }
        else if(root->left==nullptr&& root->right!=nullptr){
            root->left=root->right;
            root->right=nullptr;
            Swapping(root->left);
        }
        else {
            root->right=root->left;
            root->left=nullptr;
            Swapping(root->right);
        }
        
    }
};
int main(){

}