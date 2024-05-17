#include<bits/stdc++.h>
using namespace std;
void print(vector<int> & vec){
    if(vec.empty()){
        cout<<"Empty Vector !!"<<endl;
        return;
    }
    cout<<"Vec : "<<vec.at(0);
    for(int i=1;i<vec.size();i++){
        cout<<","<<vec[i];
    }
    cout<<endl;
}
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> result;
        bitset<51> st;
        bitset<51> st2;
        for(int i=0;i<A.size();i++){
            st.set(A[i]);
            st2.set(B[i]);
            int count=(st & st2).count();
            result.push_back(count);
        }
        return result;
    }
};
int main(){
    vector<int> A={2,3,1};
    vector<int> B={3,1,2};
    Solution obj;
    vector<int> result=obj.findThePrefixCommonArray(A,B);
    cout<<"Resultant ";
    print(result);
}