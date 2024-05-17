#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> mat){
    if(mat.empty()){
        cout<<"Empty matrix!"<<endl;
        return;
    }
    cout<<"Matrix :"<<endl;
    for(auto x:mat){
        cout<<"["<<x[0];
        for(int i=1;i<x.size();i++){
            cout<<","<<x[i];
        }
        cout<<"]"<<endl;
    }
}
void print(vector<int> row){
    if(row.empty()){
        cout<<"Empty Row"<<endl;
        return;
    }
    cout<<"Row :"<<row[0];
    for(int i=1;i<row.size();i++) cout<<","<<row[i];
    cout<<endl;
}
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> diagonal;
        int j=0;
        int rowCount=mat.size();
        int colCount=mat.at(0).size();
        for(int i=0;i<mat.at(0).size();i++){
            int k=i;
            vector<int> temp;
            while(j<rowCount && k<colCount){
                temp.push_back(mat.at(j).at(k));
                j++;k++;
            }
            j=0;
            diagonal.push_back(temp);
        }
        j=0;
        for(int i=1;i<mat.size();i++){
            int k=i;
            vector<int> temp;
            while(k<rowCount && j<colCount){
                temp.push_back(mat.at(k).at(j));
                j++;k++;
            }
            j=0;
            diagonal.push_back(temp);
        }
        int diag=0;j=0;
        for(int i=0;i<diagonal.size();i++) sort(diagonal.at(i).begin(), diagonal.at(i).end());
        for(int i=0;i<mat.at(0).size();i++){
            int k=i; int index=0;
            vector<int> temp=diagonal[diag++];
            while(j<rowCount && k<colCount && index<temp.size()){
                mat[j++][k++]=temp[index++];
            }
            j=0;
        }
        j=0;
        for(int i=1;i<mat.size();i++){
            int k=i;int index=0;
            vector<int> temp=diagonal[diag++];
            while(k<rowCount && j<rowCount && index<temp.size()){
                mat[k++][j++]=temp[index++];
            }
            j=0;
        }
        return mat;
    }
};
int main(){
    vector<vector<int>> mat={{9,8,7},{6,5,4},{3,2,1}};
    print(mat);
    Solution obj;
    print(obj.diagonalSort(mat));
}