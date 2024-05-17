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
    vector<TreeNode* >buffer;
public:
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        pre_order(root);
        root->left=nullptr;
        root->right=nullptr;
        make_tree(buffer,root);
    }
    void make_tree(vector<TreeNode*> buffer,TreeNode *root){
        for(int i=1;i<buffer.size();i++){
            root->left=nullptr;
            root->right=buffer[i];
            root=root->right;
        }
    }
    void pre_order(TreeNode* root){
        if(root==nullptr) return;
        buffer.push_back(root);
        pre_order(root->left);
        pre_order(root->right);
    }
};
int main(){
    TreeNode*root=new TreeNode(1,new TreeNode(2,new TreeNode(3),new TreeNode(4)),new TreeNode(5,nullptr,new TreeNode(6)));
    Solution s;
    s.flatten(root);

}