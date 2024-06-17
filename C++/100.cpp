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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr && q!=nullptr) return false;
        if(p!=nullptr && q==nullptr) return false;
        return check(p,q);
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