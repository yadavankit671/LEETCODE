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
    void treebuilder(vector<int> &data,int left,int right){

    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<int> data;
        for(int i=0;i<traversal.length();i++){
            if(i>0 && i<traversal.length() && traversal[i-1]=='-' && traversal[i]=='-' && traversal[i+1]=='-') data.push_back(-1);
            if(traversal[i]!='-') data.push_back(traversal[i]-'0');
        }
        for(auto x: data) cout<<x<<endl;
    }
};
int main(){
    string traversal="1-401--349---90--88";
    Solution obj;
    obj.recoverFromPreorder(traversal);
}