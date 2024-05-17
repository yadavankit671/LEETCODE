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
    if(!node) {
        cout<< "List is empty"<< endl;
        return;
    }
    cout<<"List : "<<node->val;
    node=node->next;
    while(node){
        cout<<"-->"<<node->val;
        node=node->next;
    }
    cout<<endl<<endl;
}
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> nodes;
        while(head){
            nodes.push_back(head->val);
            head = head->next;
        }
        ListNode* res=new ListNode(nodes.at(nodes.size()-1));
        for(int i=nodes.size()-2;i>=0;i--){
            if(res->val<=nodes.at(i)){
                res=new ListNode(nodes.at(i),res);
            }
        }
        return res;
    }
};
int main(){
    vector<int> nums={138,466,216,67,642,978,264,136,463,331,60,600,223,275,856,809,167,101,846,165,575,276,409,590,733,200,839,515,852,615,8,584,250,337,537,63,797,900,670,636,112,701,334,422,780,552,912,506,313,474,183,792,822,661,37,164,601,271,902,792,501,184,559,140,506,94,161,167,622,288,457,953,700,464,785,203,729,725,422,76,191,195,157,854,730,577,503,401,517,692,42,135,823,883,255,111,334,365,513,338,65,600,926,607,193,763,366,674,145,229,700,11,984,36,185,475,204,604,191,898,876,762,654,770,774,575,276,165,610,649,235,749,440,607,962,747,891,943,839,403,655,22,705,416,904,765,905,574,214,471,451,774,41,365,703,895,327,879,414,821,363,30,130,14,754,41,494,548,76,825,899,499,188,982,8,890,563,438,363,32,482,623,864,161,962,678,414,659,612,332,164,580,14,633,842,969,792,777,705,436,750,501,395,342,838,493,998,112,660,961,943,721,480,522,133,129,276,362,616,52,117,300,274,862,487,715,272,232,543,275,68,144,656,623,317,63,908,565,880,12,920,467,559,91,698};
    ListNode * head=new ListNode(nums.at(nums.size()-1));
    for(int i=nums.size()-2;i>=0;i--){
        head=new ListNode(nums.at(i),head);
    }
    Solution obj;
    cout<<"Resultant ";
    print(obj.removeNodes(head));
}