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
    void traversal(TreeNode *node,vector<int> & nums){
        if(node==nullptr) return; 
        nums.push_back(node->val);
        traversal(node->left,nums);
        traversal(node->right,nums);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums;
        traversal(root1,nums);
        traversal(root2,nums);
        sort(nums.begin(),nums.end());
        return nums;
    }
};
int main(){

}