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
    void traversal(TreeNode *node,int curr,long long &sum){
        if(node==nullptr){
            return;
        }
        curr=curr*10+node->val;
        traversal(node->left,curr,sum);
        traversal(node->right,curr,sum);
        if(node->left==nullptr&& node->right==nullptr) sum+=curr;
    }
public:
    int sumNumbers(TreeNode* root) {
        long long sum=0;
        traversal(root,0,sum);
        return sum;
    }
};
int main(){
    TreeNode * root=new TreeNode(4,new TreeNode(9,nullptr ,new TreeNode(1)),new TreeNode(0));
    Solution obj;
    cout<<obj.sumNumbers(root);
}