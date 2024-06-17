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
    int sum;
    Solution():sum(0) {}
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr)return 0;
        inorderSum(root, low, high);
        return sum;
    }
    void inorderSum(TreeNode * root,int low,int high){
        if(root==nullptr) return;
        inorderSum(root->left,low,high);
        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }
        inorderSum(root->right,low,high);
    }
};
int main(){

}