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
    TreeNode* TreeBuilder(int start,int end,vector<TreeNode*> &list){
        if(start>end) return nullptr;
        int mid=start+(end-start)/2;
        TreeNode *node = list[mid];
        node->left=nullptr;
        node->right=nullptr;
        node->left=TreeBuilder(start,mid-1,list);
        node->right=TreeBuilder(mid+1,end,list);
        return node;
    }
    void traversal(TreeNode *node,vector<TreeNode *> &list){
        if(node==nullptr) return;
        list.push_back(node);
        traversal(node->left,list);
        traversal(node->right,list);
    }
    static bool cmp(TreeNode* node1,TreeNode* node2){
        return node1->val<node2->val;
    }
    public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> list;
        traversal(root,list);
        sort(list.begin(),list.end(),cmp);
        TreeNode * result=TreeBuilder(0,list.size()-1,list);
        return result;
    }
};
int main(){
    TreeNode *root= new TreeNode(1,nullptr,new TreeNode(2,nullptr,new TreeNode(3,nullptr,new TreeNode(4,nullptr, new TreeNode(5)))));
    Solution obj;
    TreeNode *result=obj.balanceBST(root);
}
