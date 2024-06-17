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
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth= depthCalc(root);
        int sum=0;
        deepSum(root,0,maxDepth,sum);
        return sum;
    }
    /*
    another optimized way would be keep track of the level using currlvl and max lvl and if another high level is there we change the ans value and if currlvl matches with max level we add the values 
    */
    private:
    int depthCalc(TreeNode* root){
        if(root==nullptr ) return 0;
        if(root->left==nullptr && root->right==nullptr) return 1;
        int left=0;
        left+=depthCalc(root->left);
        int right=0;
        right+=depthCalc(root->right);
        return max(left,right)+1;
    }
    void deepSum(TreeNode*root,int Currdepth,int maxDepth,int &sum){
        if(root==nullptr)return;
        if(Currdepth+1==maxDepth) sum+=root->val;
        deepSum(root->left,Currdepth+1,maxDepth,sum);
        deepSum(root->right,Currdepth+1,maxDepth,sum);
    }
};
int main(){
    TreeNode *root=new TreeNode(1,new TreeNode(2,new TreeNode(4,new TreeNode(7),nullptr),new TreeNode(5)),new TreeNode(3,nullptr,new TreeNode(6,nullptr,new TreeNode(8))));
    Solution obj;
    cout<<obj.deepestLeavesSum(root);
}