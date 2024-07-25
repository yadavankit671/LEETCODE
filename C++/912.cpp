#include<bits/stdc++.h>
using namespace std;
class Solution {
    private :
    void merge(vector<int> &nums,int start, int mid, int end){
        int leftArraySize = mid - start + 1;
        int rightArraySize = end - mid;
        vector<int> leftArray(leftArraySize), rightArray(rightArraySize);
        for(int i = 0; i < leftArraySize; i++) leftArray[i] = nums[start + i];
        for(int i = 0; i < rightArraySize; i++) rightArray[i] = nums[mid + 1 + i];
        int i = 0, j = 0, k = start;
        while(i < leftArraySize && j < rightArraySize){
            if(leftArray[i] <= rightArray[j]){
                nums[k] = leftArray[i];
                i++;
            }else{
                nums[k] = rightArray[j];
                j++;
            }
            k++;
        }
        while(i < leftArraySize){
            nums[k] = leftArray[i];
            i++;
            k++;
        }
        while(j < rightArraySize){
            nums[k] = rightArray[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int> &nums, int start, int end){
        if(start >= end) return ;
        int mid = start + (end - start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums, mid+1, end);
        merge(nums,start,mid,end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};
int main(){

}