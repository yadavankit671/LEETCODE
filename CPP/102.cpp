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
void print (vector<vector<int>> result){
    if(result.size()==0) {
            cout<<"Empty Array "<<endl;
        return;
    }
    cout<<"Array : [";
    for(int i=0;i<result.size();i++){
        cout<<"["<<result[i][0];
        for(int j=1;j<result[i].size();j++){
            cout<<","<<result[i][j];
        }
        cout<<"]";
    }
    cout<<"]"<<endl;
}
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr ) return {};
        vector<vector<int>> result;
        result.push_back(vector<int>(1,root->val));
        traversal(root,root,result,1);
        return result;
    }
    private:
    stack<int> lvltraversed;
    void traversal(TreeNode* root,TreeNode* node,vector<vector<int>>& result,int level){
        if(node==nullptr ) return;
        if(lvltraversed.empty()||level>lvltraversed.top()){
            lvltraversed.push(level);
            vector<int> temp;
            lvl(root->left,level,1,temp);
            lvl(root->right,level,1,temp);
            if(temp.size()>0)
            result.push_back(temp);
        }
        traversal(root,node->left,result,level+1);
        traversal(root,node->right,result,level+1);
    }
    void lvl(TreeNode * root,int level,int curr,vector<int> &temp){
        if(root==nullptr) return;
        if(curr>level) return;
        if(curr==level) {
            temp.push_back(root->val);
            return;
        }
        lvl(root->left,level,curr+1,temp);
        lvl(root->right,level,curr+1,temp);
    }
};
int main(){
    Solution s;
    TreeNode *root=new TreeNode(3,new TreeNode(9,new TreeNode(7),new TreeNode(151)),new TreeNode(20,new TreeNode(15),new TreeNode(7)));
    vector<vector<int>> result=s.levelOrder(root);
    print(result);
}