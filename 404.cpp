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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        traverse(sum,root);
        return sum;
    }
    private:
    void traverse(int &sum,TreeNode* node){
        if(node==nullptr) return;
        if(node->left&& node->left->left==nullptr && node->left->right==nullptr){
            sum+=node->left->val;
        }
        traverse(sum,node->left);
        traverse(sum,node->right);
    }
};
int main(){

}