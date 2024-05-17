#include<bits/stdc++.h>
using namespace std;
void print(set<int> buff){
    if(buff.empty()){
        cout<<"Buffer is empty"<<endl;
        return;
    }
    for(auto x:buff){
        cout<<x<<",";
    }
    cout<<endl;
}
class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26,0);
        int size=word.length();
        for(int i=0;i<size;i++){
            freq[word.at(i)-'a']++;
        }
        map<int,int> buff;
        int count=0;
        for(int i=0;i<26;i++){
            if(freq.at(i)!=0){
                buff[freq.at(i)]++;
                count++;
            }
        }
        if(count==1) return true;
        if(buff.size()==1 && (*buff.begin()).first==1) return true;
        if(buff.size()!=2) return false;
        auto itr=buff.begin();
        int x=itr->first;
        int fx=itr->second;
        itr++;
        int y=itr->first;
        int fy=itr->second;
        if(fx>1 && fy>1) return false;
        if((x==1 && fx==1)|| (y==1 && fy==1)) return true;
        if(x>y && x-1==y && fx==1) return true;
        if(y>x && y-1==x && fy==1) return true;
        return false;
    }
};
int main(){
    string word="aabbc"; // a->1 b->1 c->2 d->2
    Solution obj;
    if(obj.equalFrequency(word)) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}