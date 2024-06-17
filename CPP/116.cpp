#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
    public:
    Node* connect(Node* root) {
        if(root == nullptr)return nullptr;
        traversal(root->left, root->right);
        return root;
    }
    private:
    /*
                            1
                    2               3
                4       5       6       7
            8     9  10    11 12  13 14   15
    */
    void traversal(Node* left,Node *right){
        if(left==nullptr) return ;
        left->next=right;
        traversal(left->left,left->right); // 2-3 && 4-5 connect 
        traversal(right->left,right->right); // 6-7 connect
        traversal(left->right,right->left); // 5-6 connect
    }
};
int main(){

}