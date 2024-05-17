#include<bits/stdc++.h>
using namespace std;

class BrowserHistory {
    private:
    string homepage;
    int position;
    vector<string> history;
public:
    BrowserHistory(string homepage) {
        this->homepage=homepage;
        this->position=0;
        history.push_back(homepage);
    }
    void clear(){
        int size=history.size();
        for(int i=size-1;i>position;i--)
        history.pop_back();
    }
    void visit(string url) {
        clear();
        history.push_back(url);
        position=history.size()-1;
    }
    string back(int steps) {
        if(position-steps<0) position=0;
        else
        position=position-steps;
        return history[position];
    }
    string forward(int steps) {
        if(position+steps>=history.size()) {
            position =history.size()-1;
            return history[position];
        }
        position=position+steps;
        return history[position];
    }
    void print(){
        cout<<"Browser History :"<<history[0];
        for(int i=1;i<history.size();i++)
        cout<<", "<<history[i];
        cout<<endl;
    }
};
int main(){
    cout<<"Homepage : Leetcode.com"<<endl;
    BrowserHistory *obj=new BrowserHistory("Leetcode.com");
    cout<<"Pushed google.com"<<endl;obj->visit("google.com");
    cout<<"Pushed facebook.com"<<endl;obj->visit("facebook.com");
    cout<<"Pushed youtube.com"<<endl;obj->visit("youtube.com");
    cout<<obj->back(1)<<endl;
    cout<<obj->back(1)<<endl;
    cout<<obj->forward(1)<<endl;
    cout<<"Pushed Linkedin.com"<<endl;obj->visit("linkedin.com");
    obj->print();
    cout<<obj->forward(2)<<endl;
    cout<<obj->back(2)<<endl;
    cout<<obj->back(7)<<endl;

}