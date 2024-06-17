#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int end=matrix.size()-1;\
        while(start<=end) {
            int mid=(start+end)/2;
            if(matrix[mid][0]<=target && target<=matrix[mid][matrix[mid].size()-1]){
                return check(matrix[mid],target);
            }
            else if(matrix[mid][matrix[mid].size()-1]<target){
                start=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return false;
    }
    bool check(vector<int> nums,int target){
        int start=0;
        int end=nums.size()-1;
        while(start<=end) {
            int mid=(start+end)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]<target){
                start=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return false;
    }
};
int main(){
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    Solution obj;
    cout<<obj.searchMatrix(matrix,3)<<endl;
}