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
    int solve(TreeNode * node,int &moves){
        if(node==nullptr){
            return 0;
        }
        int left=solve(node->left,moves);
        int right=solve(node->right,moves);
        moves+=abs(left)+abs(right);
        return left+right+node->val-1;
    }
public:
    int distributeCoins(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        int result=0;
        solve(root,result);
        return result;
    }
};
int main(char* args){

}