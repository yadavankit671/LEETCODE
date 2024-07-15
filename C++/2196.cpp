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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode *> nodeMap; // map to store all the nodes
        for (vector<int>& desc : descriptions) {
            int parentVal = desc[0], 
                childVal = desc[1];
            bool isLeft = desc[2] == 1;
            TreeNode *parentNode = nodeMap.count(parentVal) ? nodeMap[parentVal] : (nodeMap[parentVal] = new TreeNode(parentVal));
            TreeNode *childNode = nodeMap.count(childVal) ? nodeMap[childVal] : (nodeMap[childVal] = new TreeNode(childVal));
            if (isLeft) parentNode->left = childNode;
            else parentNode->right = childNode;
        }
        for (vector<int> &desc : descriptions) 
            nodeMap.erase(desc.at(1)); // remove all the children nodes desc.at(1) is childVal
        
        return nodeMap.begin()->second; // only one left in Map which is our root
    }
};
int main(){

}