#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int result=0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0) {
                result+=customers[i];
            }
        }
        int grumpyMax=0;
        int temp=0;
        int left=0,right=0;
        while(right<customers.size()){
            if(grumpy[right]==1){
                temp+=customers[right];
            }
            if(right-left+1>minutes){
                if(grumpy[left]==1){
                    temp-=customers[left];
                }
                left++;
            }
            grumpyMax=max(grumpyMax,temp);
        }
        return result+grumpyMax;
    }
};
int main(){

}