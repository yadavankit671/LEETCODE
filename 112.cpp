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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root ==nullptr && targetSum != 0) return false;
        return hasPathSum(root,targetSum,0);
    }
    private:
    bool hasPathSum(TreeNode* root, int targetSum,int currentSum){
        if(root == nullptr) return false;
        currentSum+=root->val;
        if(root->left ==nullptr && root->right ==nullptr && currentSum!=targetSum ){
            currentSum-=root->val;
            return false;
        }
        if(currentSum==targetSum && root->left==nullptr && root->right==nullptr) return true;
        return max(hasPathSum(root->left,targetSum,currentSum),hasPathSum(root->right,targetSum,currentSum));
    }
};
int main(){

}