#include<bits/stdc++.h>
using namespace std;
/*
[
[1,2,3,4,5,6,7,8,9,10,11,...............................] -->2
[23049823740928]
]

*/
// class Solution {
//     private: 
//     bool search(vector<int> & arr,int target){
//         int i=0;int j=arr.size()-1;
//         while(i<=j){
//             int mid=(i+j)/2;
//             if(arr[mid]==target) return true;
//             else if(arr[mid]>target) j=mid-1;
//             else i=mid+1;
//         }
//         return false;
//     }
//     public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         ios_base::sync_with_stdio(false);
//         for(int i=0;i<matrix.size();i++){
//             if(matrix.at(i).at(0)<=target && matrix.at(i).at(matrix.at(i).size()-1)>=target){
//                 if(search(matrix.at(i),target)) return true;
//             }
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0; int col=matrix.at(0).size()-1;
        while(row >=0 && row<=matrix.size() && col>=0 && col <=matrix.at(0).size()){
            if(matrix.at(row).at(col)==target) return true;
            if(matrix.at(row).at(col)>target) col--;
            else row++;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix={{1,2,3,12,15},{11,12,13,14,16},{20,21,22,23,24}};
    int target=14;
    Solution obj;
    cout<<obj.searchMatrix(matrix,target)<<endl;

}