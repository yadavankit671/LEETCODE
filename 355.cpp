#include<bits/stdc++.h>
using namespace std;
class Twitter {
    private:
    struct Node{
        int tweet_id;
        int user_id;
        Node *next;
        Node *prev;
        Node(int tweet_id, int user_id): tweet_id(tweet_id),user_id(user_id),next(nullptr),prev(nullptr){}
    };
    Node *head;
    Node* tail;
    map<int,vector<int>>users;
    bool search(vector<int> followerlist,int follower_id){
        for(auto x: followerlist) if(x==follower_id) return true;
        return false;
    }
    public:
    Twitter() {
        head=nullptr;tail=nullptr;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    void postTweet(int userId, int tweetId) {
        Node *newNode=new Node(tweetId,userId);
        Node* temp=head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=temp;
        temp->prev=newNode;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        Node * node=head->next;
        vector<int> temp=users[userId];
        while(node!=tail){
            if(result.size()>=10) break;
            if(node->user_id==userId || search(temp,node->user_id)) result.push_back(node->tweet_id);
            node=node->next;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].push_back(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        for(int i=0;i<users[followerId].size();i++){
            if(users[followerId][i]==followeeId) {
                users[followerId].erase(users[followerId].begin()+i);
                break;
            }
        }
    }
};
/*
["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
[  [],        [1,5],      [1],        [1,2],     [2,6],       [1],        [1,2],       [1]]
*/
int main(){
    Twitter tweet;
    tweet.postTweet(1,5);
    tweet.getNewsFeed(1);
}