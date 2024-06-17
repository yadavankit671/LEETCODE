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
    int countNodes(TreeNode* root) {
        if( root == nullptr ) return 0;
        if(root->left==nullptr && root->right==nullptr ) return 1;
        int result=0;
        traversal(result,root);
        return result;
    }
    private:
    void traversal(int &counter,TreeNode *root){
        if(root==nullptr) return;
        counter++;
        traversal(counter,root->left);
        traversal(counter,root->right);
    }
};
int main(){

}