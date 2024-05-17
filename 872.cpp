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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string one;
        string two;
        Traversal(root1,one);
        Traversal(root2,two);
        return one==two;
    }
    void Traversal(TreeNode* root,string &values){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr){
            values=values+to_string(root->val)+",";
            return;
        }
        Traversal(root->left,values);
        Traversal(root->right,values);
    }
};
int main(){

}