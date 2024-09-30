#include<bits/stdc++.h>
using namespace std;
class CustomStack {
    vector<int> st;
    int size;
public:
    CustomStack(int maxSize) {
        this->size = maxSize;
    }
    
    void push(int x) {
        if(st.size() == size) return;
        st.push_back(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int ret = *st.rbegin();
        st.pop_back();
        return ret;
    }
    
    void increment(int k, int val) {
        int len = min<int>(st.size(), k);
        for(int i = 0;i < len; i++){
            st[i] +=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
int main(){

}