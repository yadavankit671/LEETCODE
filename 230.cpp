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
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return -1;
        if(root->right==nullptr && root->left==nullptr) return root->val;
        set<int> nodes;
        traversal(nodes,root);
        int counter =0;
        for(auto x:nodes){
            counter++;
            if(counter==k) return x;
        }
        return -1;
    }
    private:
    void traversal(set<int>&nodes,TreeNode* root){
        if(root==nullptr) return;
        nodes.insert(root->val);
        traversal(nodes,root->left);
        traversal(nodes,root->right);
    }
};
int main(){

}