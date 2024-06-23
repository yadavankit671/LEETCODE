#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node *prev;
    Node *next;
    Node(int val){
        this->val=val;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
class myList{
    private:
    Node *head;
    Node *tail;
    public:
    myList(){
        head=nullptr;
        tail=nullptr;
    }
    void addLast(int val){
        Node *newNode= new Node(val);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }
        else {
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
    }
    int getFirst(){
        return head!=nullptr? head->val : INT_MIN;
    }
    int getLast(){
        return tail!=nullptr ? tail->val : INT_MIN;
    }
    void removeLast(){
        if(head==tail){
            head=nullptr;
            tail=nullptr;
        }
        else{
            tail=tail->prev;
            tail->next=nullptr;
        }
    }
    void removeFirst(){
        if(head==tail){
            head=nullptr;
            tail=nullptr;
        }
        else{
            head=head->next;
            head->prev=nullptr;
        }
    }
    bool isEmpty(){
        return head==nullptr;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int size= nums.size();
        int left=0;
        int right=0;
        int result=0;
        myList *maxList=new myList();
        myList *minList=new myList();
        while(right<size){
            while(!maxList->isEmpty() && nums[right]>maxList->getLast()){
                maxList->removeLast();
            }
            while(!minList->isEmpty() && nums[right]<minList->getLast()){
                minList->removeLast();
            }
            maxList->addLast(nums[right]);
            minList->addLast(nums[right]);
            while(!minList->isEmpty() && !maxList->isEmpty() && maxList->getFirst()-minList->getFirst()>limit){
                if(nums[left]==minList->getFirst()){
                    minList->removeFirst();
                }
                if(nums[left]==maxList->getFirst()){
                    maxList->removeFirst();
                }
                left++;
            }
            result=max(result,right-left+1);
            right++;
        }
        return result;
    }
};
int main(){

}