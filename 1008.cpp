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
    void buildTree(vector<int> preorder,int i,int j,TreeNode *parent){
        if(parent==nullptr) return;
        if(i>j || i>=preorder.size() || j>=preorder.size() ) return ;
        int right =i;
        for(int k=i;k<=j;k++) 
            if(preorder[k]>parent->val) {
                right=k;
                break;
            }
        if(preorder[i]<parent->val) parent->left=new TreeNode(preorder[i]);
        if(preorder[right]>parent->val) parent->right=new TreeNode (preorder[right]);
        buildTree(preorder,i+1,(right!=i)?right-1:j,parent->left);
        buildTree(preorder,(right==i)?i+1:right+1,j,parent->right);
    }
    public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root=new TreeNode(preorder[0]);
        buildTree(preorder,1,preorder.size()-1,root);
        return root;
    }
};
void traversal(TreeNode * root){
    if(root==nullptr) return;
    cout<<root->val<<" ";
    traversal(root->left);
    traversal(root->right);
}
int main(){
    vector<int> preorder={8,5,1,7,10,12};
    Solution obj;
    TreeNode *root=obj.bstFromPreorder(preorder);
    traversal(root);

}