#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        for(int i = 0; i < arr.size();i++){
            if(arr[i]==0){
                arr.insert(arr.begin()+i+1,0);
                i++;
            }
        }
        n=arr.size()-n;
        while(n!=0){
            arr.pop_back();
            n--;
        }
    }
    void print(vector<int>& arr){
        cout<<"List : {"<<arr[0];
        for(int i=1;i<arr.size();i++){
            cout<<"-->"<<arr[i];
        }
        cout<<"}"<<endl;
    }
};
int main(){
    vector<int> arr={1,0,2,3,0,4,5,0};
    Solution s;
    s.duplicateZeros(arr);
    s.print(arr);
}