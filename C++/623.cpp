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
    void solve(TreeNode * node,int depth,int val,int curr_depth){
        if(node==nullptr || curr_depth>depth) return;
        if(curr_depth+1==depth){
            node->left=new TreeNode(val,node->left,nullptr);
            node->right=new TreeNode(val,nullptr,node->right);
            return;
        }
        solve(node->left,depth,val,curr_depth+1);
        solve(node->right,depth,val,curr_depth+1);
    }
    public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            return new TreeNode(val,root,nullptr);
        }
        solve(root,depth,val,1);
        return root;
    }
};
int main(){

}