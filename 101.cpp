#include<bits/stdc++.h>
using namespace std;
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
    bool isSymmetric(TreeNode* root) {
        if(root ==nullptr) return true;
        if(root->left!=nullptr && root->right==nullptr) return false;
        if(root->right!=nullptr && root->left==nullptr) return false;
        return check(root->left,root->right);
    }
    bool check(TreeNode * node1, TreeNode *node2){
        if(node1!=nullptr && node2==nullptr) return false;
        if(node1==nullptr && node2!=nullptr) return false;
        if(node1==nullptr && node2==nullptr) return true;
        if(node1->val !=node2->val) return false;
        bool flag1=(check(node1->left,node2->right)==true)?true:false;
        bool flag2=(check(node1->right,node2->left)==true)?true:false;
        return (flag1==true && flag2==true)?true:false;
    }
};
int main(){

}
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(root ==nullptr) return true;
//         if(root->left!=nullptr && root->right==nullptr) return false;
//         if(root->right!=nullptr && root->left==nullptr) return false;
//         //taking root ->left
//         invertTree(root->left);
//         return check(root->left,root->right);
//     }
//     bool check(TreeNode * node1,TreeNode * node2) {
//         if(node1==nullptr && node2==nullptr) return true;
//         if(node1!=nullptr && node2==nullptr) return false;
//         if(node1==nullptr && node2!=nullptr) return false;
//         if(node1->val!=node2->val) return false;
//         bool flag1= (check(node1->left,node2->left)==false)?false:true;
//         bool flag2= (check(node1->right,node2->right)==false)?false:true;
//         return (flag1==true && flag2==true)?true:false;
//     }
//     void invertTree(TreeNode* root){
//         if(root==nullptr)return;
//         if(root->left==nullptr && root->right==nullptr)return;
//         else if(root->left!=nullptr && root->right!=nullptr){
//             TreeNode* temp1=root->left;
//             TreeNode* temp2=root->right;
//             root->left=temp2;
//             root->right=temp1;
//             invertTree(root->left);
//             invertTree(root->right);
//         }
//         else if(root->left==nullptr&& root->right!=nullptr){
//             root->left=root->right;
//             root->right=nullptr;
//             invertTree(root->left);
//         }
//         else {
//             root->right=root->left;
//             root->left=nullptr;
//             invertTree(root->right);
//         }
//     }
// };