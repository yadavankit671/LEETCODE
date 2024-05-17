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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        pair<int,int> maximum(make_pair(INT_MIN,-1));
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maximum.first){
                maximum.first=nums[i];
                maximum.second=i;
            }
        }
        int mid=maximum.second;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=treebuilder(nums,0,mid);
        root->right=treebuilder(nums,mid+1,nums.size());
        return root;
    }
    TreeNode* treebuilder(vector<int>&nums,int low,int high){
        if(low>=high) return nullptr;
        pair<int,int> maximum(make_pair(INT_MIN,-1));
        for(int i=low;i<high;i++){
            if(nums[i]>maximum.first){
                maximum.first=nums[i];
                maximum.second=i;
            }
        }
        TreeNode *node=nullptr;
        node=new TreeNode(maximum.first);
        node->left=treebuilder(nums,low,maximum.second);
        node->right=treebuilder(nums,maximum.second+1,high);
        return node;
    }
};
int main(){
    vector<int> nums={3,2,1,6,0,5};
    Solution obj;
    obj.constructMaximumBinaryTree(nums);
}