#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    vector<int> stack;
    int min;
    MinStack() {
        stack.clear();
        min = INT16_MAX;
    }
    
    void push(int val) {
        if(stack.size()==0)min=val;
        stack.push_back(val);
        if(val<min)min=val;
    }
    
    void pop() {
        if(stack.at(stack.size() - 1)==min){
            stack.pop_back();
            min=*min_element(stack.begin(), stack.end());
            return;
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.at(stack.size() - 1);
    }
    
    int getMin() {
        return min;
    }
};
int main(){

}