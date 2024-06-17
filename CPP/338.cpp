#include<bits/stdc++.h>
using namespace std;
void print(vector<int> result){
    if(result.size()==0){
        cout<<"Empty List "<<endl;
        return;
    }
    cout<<"List : ["<<result[0];
    for(int i=1;i<result.size();i++){
        cout<<","<<result[i];
    }
    cout<<"]"<<endl;
}
class Solution {
    private:
    int no_of_bits(int i){
        int counter=0;
        while(i>0){
            if(i%2==1){
                counter++;
            }
            i=i/2;
        }
        return counter;
    }
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0;i<=n;i++){
            result.push_back(no_of_bits(i));
        }
        return result;
    }
};
int main(){
    int n=15;
    Solution obj;
    vector<int> result=obj.countBits(n);
    print(result);
}