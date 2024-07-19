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
    TreeNode* traversal(TreeNode * node, set<int> & st,vector<TreeNode *> &result,bool push){
        if(node == nullptr) return nullptr;
        bool del = st.find(node->val)!=st.end();
        if(push && !del) result.push_back(node);
        node->left= traversal(node->left,st,result,del);
        node->right= traversal(node->right,st,result,del);
        return del ? nullptr : node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        set<int> st;
        for(int x : to_delete) st.insert(x);
        traversal(root,st,result,true); 
        return result;
    }
};
int main(){
    
}