#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return nullptr;
        vector<int> list;
        while(head){
            list.push_back(head->val);
            head = head->next;
        }
        TreeNode* root=TreeBuilder(list,0,list.size()-1);
        return root;
    }
    TreeNode* TreeBuilder(vector<int>list,int start,int end){
        if(start>end) return nullptr;
        int mid=(start+end)/2;
        TreeNode *root= new TreeNode(list[mid],TreeBuilder(list,start,mid-1),TreeBuilder(list,mid+1,end));
        return root;
    }

};
int main(){

}