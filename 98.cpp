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
    bool isValidBST(TreeNode* root) {
        return traversal(root);
    }
    private:
    bool traversal(TreeNode *root){
        if( root==nullptr ) return true;
        if(root->left && root->left->val>=root->val) return false;
        if(root->right && root->right->val<=root->val) return false;
        bool lft=true;
        bool rgt=true;
        if(root->left&& (root->left->left ||root->left->right) ){
            lft=left(root->left,root);
        }
        if(root->right && (root->right->right || root->right->left)){
            rgt=right(root->right,root);
        }
        return min(min(lft,rgt),min(traversal(root->left),traversal(root->right)));
    }
    bool left(TreeNode* root,TreeNode *parent){
        if(root==nullptr) return true;
        if(root->val>=parent->val) return false;
        if(root->left && root->left->val >=parent->val) return false;
        if(root->right && root->right->val>=parent->val) return false;
        return min (left(root->left,parent),left(root->right,parent));
    }
    bool right(TreeNode* root,TreeNode *parent){
        if(root==nullptr) return true;
        if(root->val <= parent->val) return false;
        if(root->left && root->left->val <=parent->val) return false;
        if(root->right && root->right->val<=parent->val) return false;
        return min (right(root->left,parent),right(root->right,parent));
    }
};
int main(){
    Solution obj;
    //[3,1,5,0,2,4,6]
    TreeNode *root=new TreeNode(3,new TreeNode(1,new TreeNode(0),new TreeNode(2)),new TreeNode(5,new TreeNode(4),new TreeNode(6)));
    if(obj.isValidBST(root)) cout<<"Valid BST";
    else cout<<"Invalid BST";
}