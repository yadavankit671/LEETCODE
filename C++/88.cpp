#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=m;i<(m+n);i++){
            nums1.at(i)=nums2.at((i-m));
        }
        quickSort(nums1,0,nums1.size()-1);
    }
    void swap(int *x, int *y) {
        int temp=*x;
        *x=*y;
        *y=temp;
    }
    int partition(vector<int>& arr, int low, int high){
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    void quickSort(vector<int>& arr, int low, int high){
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};

int main(){

}