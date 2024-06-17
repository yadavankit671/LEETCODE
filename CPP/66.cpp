#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if(digits.size()==0){
            digits.push_back(1);
        }
        int carry=0;
        digits.at(size-1)=digits.at(size-1)+1;
        for(int i=size-1; i>=0;i--){
            digits.at(i)=digits.at(i)+carry;
            carry=0;
            if(digits.at(i)>9){
                carry=1;
                digits.at(i)=0;
            }
        }
        if(carry==1){
            int temp=digits.at(0);
            digits.clear();
            digits.push_back(carry);
            for(int i=1; i<=size;i++){
                digits.push_back(0);
            }
        }
        return digits;
    }
};
int main(){
    Solution s;
    vector<int> digits={9,9};
    vector<int> plusOne=s.plusOne(digits);
    for(int i=0; i<plusOne.size(); i++){
        cout<<plusOne.at(i)<<endl;
    }

}