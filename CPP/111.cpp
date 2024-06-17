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
    int minDepth(TreeNode* root) {
        if(root ==nullptr ) return 0;
        if(root ->left==nullptr && root->right ==nullptr) return 1;
        int left=(root->left)?1:999999;
        left+=minDepth(root->left);
        int right=(root->right)?1:999999;
        right+=minDepth(root->right);
        return min(left,right);
    }
};
int main(){

}