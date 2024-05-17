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
    void solve (TreeNode *parent,TreeNode *child,int low,int high,int dir){
        if(parent==nullptr || child==nullptr) return;
        if(child->val<low) {
            if(dir==0) {
                if(child->right)
                    parent->left=child->right;
                
                else parent->left=nullptr;
            }
            else {
                if(child->right)
                    parent->right=child->right;
                else parent->right=nullptr;
            }
        }
        else if(child->val>high){
            if(dir==0) {
                if(child->left)
                    parent->left=child->left;
                else parent->left=nullptr;
            }
            else {
                if(child->left) 
                    parent->right=child->left;
                else
                parent->right=nullptr;
            }
        }
        if(dir==0 && parent->left && (parent->left->val<low || parent->left->val>high))
        solve(parent,parent->left,low,high,dir);
        if(dir==1 && parent->right && (parent->right->val<low || parent->right->val>high))
        solve(parent,parent->right,low,high,dir);
        if(parent->left){
            solve(parent->left,parent->left->left,low,high,0);
            solve(parent->left,parent->left->right,low,high,1);
        }
        if(parent->right){
            solve(parent->right,parent->right->left,low,high,0);
            solve(parent->right,parent->right->right,low,high,1);
        }
    }
    public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==nullptr) return nullptr;
        if(root->val<low){
            root=root->right;
            root=trimBST(root,low,high);
        }
        if(root->val>high){
            root=root->left;
            // root need to be resolved first and then anything else
            root=trimBST(root,low,high);
        }
        if(root->left)
        solve(root,root->left,low,high,0);
        if(root->right)
        solve(root,root->right,low,high,1);
        return root;
    }
};
int main(){

}