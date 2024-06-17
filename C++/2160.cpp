#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSum(int num) {
        vector<int> buffer;
        while(num>0){
            buffer.push_back(num%10);
            num/=10;
        }   
        sort(buffer.begin(),buffer.end());
        int num1=buffer.at(0);
        num1=num1*10+buffer.at(3);
        int num2=buffer.at(1);
        num2=num2*10+buffer.at(2);
        return num1+num2;
    }
};
int main(){

}