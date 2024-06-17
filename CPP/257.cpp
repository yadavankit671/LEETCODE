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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string curr="";
        traversal(root,curr,result);
        return result;
    }
    void print(vector<string> result){
        if(result.size()==0){
            cout<<"List is empty!"<<endl;
            return;
        }
        cout<<"List :[ "<<result[0];
        for(int i=1; i<result.size();i++){
            cout<<", "<<result[i];
        }
        cout<<"]"<<endl;
    }
    private:
    void traversal(TreeNode *root,string curr,vector<string>& result) {
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr){
            curr+=to_string(root->val);
            result.push_back(curr);
            return;
        }
        string temp=curr;
        if(root->left!=nullptr){
            curr+=to_string(root->val);
            curr+="->";
            traversal(root->left,curr,result);
        }
        if(root->right!=nullptr){
            temp+=to_string(root->val);
            temp+="->";
            traversal(root->right,temp,result);
        }
    }
};
int main(){
    TreeNode * root=new TreeNode(1,new TreeNode(2,nullptr,new TreeNode(5)),new TreeNode(3));
    Solution s;
    vector<string> result=s.binaryTreePaths(root);
    s.print(result);
}