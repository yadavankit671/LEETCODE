#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    int countBouquet(vector<int> & array,int day,int k){
        int count=0,consecutive=0;
        for(int i=0;i<array.size();i++){
            if(array[i]<=day){
                consecutive++;
            }
            else consecutive=0;
            if(consecutive==k){
                count++;
                consecutive=0;
            }
        }
        return count;
    }
    public :
    int minDays(vector<int> & array,int m,int k){
        if(m*k>array.size()) return -1;
        int maxi=*max_element(array.begin(),array.end());
        int mini=1;
        int result=-1;
        while(mini<=maxi){
            int mid=mini+(maxi-mini)/2;
            int count=countBouquet(array,mid,k);
            if(count>=m){
                result=mid;
                maxi=mid-1;
            }
            else mini=mid+1;
        }
        return result;
    }
};
int main(){

}