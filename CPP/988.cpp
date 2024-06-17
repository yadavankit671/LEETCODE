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
    void traversal(vector<string> & str,TreeNode *root,string curr){
        if(root==nullptr) return;
        curr+=char(root->val+'a');
        if(root->left==nullptr && root->right==nullptr){
            string s=curr;
            reverse(s.begin(),s.end());
            str.push_back(s);
            return;
        }
        traversal(str,root->left,curr);
        traversal(str,root->right,curr);
    }
    string res(vector<string> &str){
        auto smallestString = *std::min_element(str.begin(), str.end());
        return smallestString;
    }
    public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string>st;
        traversal(st,root,"");
        return res(st);
    }
};
int main(){ //0,1,2,3,4,3,4
    TreeNode *root=new TreeNode(14,new TreeNode(13,new TreeNode(9,new TreeNode(0,new TreeNode(7,new TreeNode(14),new TreeNode(10)),new TreeNode(9,new TreeNode(10),new TreeNode(18))),new TreeNode(19,new TreeNode(24,new TreeNode(10),new TreeNode(17)),new TreeNode(16,new TreeNode(1),new TreeNode(11)))),new TreeNode(21,new TreeNode(8,new TreeNode(16,new TreeNode(6),new TreeNode(4)),new TreeNode(18,new TreeNode(13),new TreeNode(12))),new TreeNode(1,new TreeNode(10,new TreeNode(14),new TreeNode(19)),new TreeNode(10,new TreeNode(22),new TreeNode(12))))),new TreeNode(8,new TreeNode(6,new TreeNode(7,new TreeNode(16,new TreeNode(8),new TreeNode(12)),new TreeNode(0,new TreeNode(21),nullptr)),new TreeNode(6,new TreeNode(5),new TreeNode(8))),new TreeNode(14,new TreeNode(24,new TreeNode(6),new TreeNode(16)),new TreeNode(9,new TreeNode(9),new TreeNode(22)))));
    Solution obj;
    cout<<"\nResult :" <<obj.smallestFromLeaf(root);
}