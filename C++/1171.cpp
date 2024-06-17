#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print(ListNode *node){
        if(!node){
            cout<<"Empty List"<<endl;
            return;
        }
        cout<<"List : "<<node->val;
        node=node->next;
        while(node){
            cout<<"-->"<<node->val;
            node=node->next;
        }
        cout<<endl;
    }
    void print(vector<int> vec){
        if(vec.empty()){
            cout<<"Empty vector"<<endl;
            return;
        }
        cout<<"vector : ";
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i]<<",";
        }
        cout<<endl;
    }
class Solution {
    private: 
    void check(vector<int> &vec){
        vector<int> newVEc;
        int i=0;
        int j=0;
        for(;i<vec.size();i++){
            int sum=vec[i];
            if(sum==0) {
                vec.erase(vec.begin()+i);
                i=-1;
            }
            else{
                for(j=i+1;j<vec.size();j++){
                    sum+=vec[j];
                    if(sum==0){
                        vec.erase(vec.begin()+i,vec.begin()+j+1);
                        i=-1;break;
                    }
                }
            }
        }
    }
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head==nullptr) return head;
        if(head->val ==0 && head->next==nullptr) return nullptr;
        vector<int> lst;
        ListNode *temp=head;
        while(temp){
            lst.push_back(temp->val);
            temp=temp->next;
        }
        check(lst);
        if(lst.empty()) return nullptr;
        ListNode *result=new ListNode(-1);
        result->next=head;
        head=result;
        for(int i=0;i<lst.size();i++){
            head->next->val=lst[i];
            head=head->next;
        }
        head->next=nullptr;
        return result->next;
    }
};
int main(){
    vector<int> vals={2,5,-3,-4,1,6,-2,-5};
    ListNode *head=nullptr;
    for(int i=vals.size()-1;i>=0;i--) head=new ListNode(vals[i],head);
    Solution obj;
    print(head);
    head=obj.removeZeroSumSublists(head);
    cout<<"Resultant ";
    print(head);
}