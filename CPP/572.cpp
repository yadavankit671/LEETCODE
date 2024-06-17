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
    bool flag=false;
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root ==nullptr && subRoot ==nullptr) return true;
        if(root!=nullptr && subRoot==nullptr) return true;
        if(root->val==subRoot->val && root->left==nullptr && root->right==nullptr&& subRoot->left==nullptr && subRoot->right==nullptr) return true;
        inorder(root,subRoot);
        return flag;
    }
    void inorder(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr) return ;
        if(root->val==subRoot->val){
            flag=(flag==true)?true:check(root,subRoot);
            if(flag==true) return;
        }
        inorder(root->left,subRoot);
        inorder(root->right,subRoot);
    }
    bool check(TreeNode * node1, TreeNode *node2){
        if(node1!=nullptr && node2==nullptr) return false;
        if(node1==nullptr && node2!=nullptr) return false;
        if(node1==nullptr && node2==nullptr) return true;
        if(node1->val !=node2->val) return false;
        bool flag1=(check(node1->left,node2->left)==true)?true:false;
        bool flag2=(check(node1->right,node2->right)==true)?true:false;
        return (flag1==true && flag2==true)?true:false;
    }
};
int main(){

}