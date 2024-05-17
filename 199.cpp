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
    /*void traversal(TreeNode * lt,TreeNode *rt,TreeNode* rightmost,vector<TreeNode *>& nodes){
        if(lt==nullptr && rt==nullptr) return;
        //cout<<"last call : "<<((lt)?lt->val:INT_MIN)<<"\t"<<((rt)?rt->val:INT_MIN)<<endl;
        if(rightmost && rightmost->right) rightmost=rightmost->right;
        else if(rightmost && rightmost->left) rightmost=rightmost->left;
        else if(rt && rt->right) rightmost=rt->right;
        else if(rt && rt->left) rightmost=rt->left;
        else if(lt && lt->right) rightmost=lt->right;
        else if(lt && lt->left) rightmost=lt->left;
        if(rightmost && find(nodes.begin(),nodes.end(),rightmost)==nodes.end())
        nodes.push_back(rightmost);
        traversal((lt)?lt->left:nullptr,(lt)?lt->right:nullptr,rightmost,nodes);
        traversal((rt)?rt->left:nullptr,(rt)?rt->right:nullptr,rightmost,nodes);
    }*/
    void traversal(TreeNode *node,vector<int>& res,int level){
        if(node==nullptr) return;
        if(level==res.size()){
            res.push_back(node->val);
        }
        traversal(node->right,res,level+1);
        traversal(node->left,res,level+1);

    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        // if(root->left==nullptr && root->right==nullptr) return {root->val};
        // vector<TreeNode *> result;
        // result.push_back(root);
        // TreeNode* rightmost=nullptr;
        // if(root->right)rightmost=root->right;
        // else rightmost=root->left;
        // result.push_back(rightmost);
        vector<int> temp;
        //traversal(root->left,root->right,rightmost,result);
        //for(auto x: result)temp.push_back(x->val);
        traversal(root,temp,0);
        return temp;
    }
};
int main(){
    TreeNode *root=new TreeNode(1,new TreeNode(2,new TreeNode(5,new TreeNode(7,nullptr,new TreeNode(8)),nullptr),new TreeNode(6)),new TreeNode(3,new TreeNode(4),nullptr));
    Solution obj;
    vector<int> result=obj.rightSideView(root);
    for(auto x: result)cout<<x<<endl;
}