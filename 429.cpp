#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
    public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return {};
        vector<vector<int>> result;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                Node* curr_node= q.front();
                q.pop();
                temp.push_back(curr_node->val);
                for(auto children: curr_node->children){
                    q.push(children);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};
int main(){

}