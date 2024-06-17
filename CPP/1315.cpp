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
    void traversal(TreeNode *node,TreeNode *parent,TreeNode *grandParent,int &sum){
        if(node==nullptr)   return;
        if(grandParent!=nullptr && grandParent->val%2==0) sum+=node->val;
        grandParent=parent;
        parent=node;
        traversal(node->left,parent,grandParent,sum);
        traversal(node->right,parent,grandParent,sum);
    }
    public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        traversal(root,nullptr,nullptr,sum);
        return sum;
    }
};
int main(){
    TreeNode *root=new TreeNode(6,new TreeNode(7,new TreeNode(2,new TreeNode(9),nullptr),new TreeNode(7,new TreeNode(1),new TreeNode(4))),new TreeNode(8,new TreeNode(1),new TreeNode(3,nullptr,new TreeNode(5))));
    Solution obj;
    cout<<obj.sumEvenGrandparent(root);
}