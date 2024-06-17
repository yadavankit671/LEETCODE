#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    int partition(vector<int>& capital,vector<int>& profits,int low,int high) {
        int pivot=capital[high];
        int i=low-1;
        for (int j=low;j<high;j++) {
            if (capital[j]<pivot || (capital[j]==pivot&&profits[j]>profits[high])) { 
                i++;
                swap(capital[i],capital[j]);
                swap(profits[i],profits[j]);
            }
        }
        swap(capital[i+1],capital[high]);
        swap(profits[i+1],profits[high]);
        return i+1;
    }

    void quickSort(vector<int>& capital,vector<int>& profits,int low,int high) {
        if (low<high) {
            int pi=partition(capital,profits,low,high);
            quickSort(capital,profits,low,pi-1);
            quickSort(capital,profits,pi+1,high);
        }
    }
public:
    int findMaximizedCapital(int k,int w,vector<int>& profits,vector<int>& capital) {
        // sorts by capital and if two capital[i] & capital[j] are same then it prioritizes maximum profits
        quickSort(capital,profits,0,capital.size()-1); 
        priority_queue<int> pq;
        int currIndex=0;
        for (int i=0;i<k;i++) {
            for (;currIndex<capital.size()&&capital[currIndex]<=w;currIndex++) 
                pq.push(profits[currIndex]);
            if (!pq.empty()) {
                w+=pq.top();
                pq.pop();
            }
            else break;
        }
        return w;
    }
};
int main(){
    //k=2,w=0,profits=[1,2,3],capital=[0,1,1]
    int k=2,w=0;
    vector<int> profits={1,3,2,4,2};
    vector<int> capital={0,1,1,1,0};
    Solution obj;
    cout<<obj.findMaximizedCapital(k,w,profits,capital);
}