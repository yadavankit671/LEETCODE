#include<bits/stdc++.h>
using namespace std;
class Solution {
    
    private:
    void solve(vector<vector<int>> & matrix,vector<vector<bool>> mat,vector<int> &result,int dir,int n,int x,int y){
        if(result.size()==n*matrix.at(0).size() || x<0 || x>=n || y<0 || y>=matrix.at(0).size()) return;
        switch(dir){
            case 0:{
                int i=x;
                int j=y;
                while(j<matrix.at(0).size() && !mat[i][j]){
                    mat[i][j] = true;
                    result.push_back(matrix[i][j]);
                    j++;
                }
                y=j-1;
                x++;
                dir++;
                solve(matrix,mat,result,dir,n,x,y);
                break;
            }
            case 1:{
                int i=x;
                int j=y;
                while(i<n&& !mat[i][j]){
                    mat[i][j]=true;
                    result.push_back(matrix[i][j]);
                    i++;
                }
                x=i-1;
                y--;
                dir++;
                solve(matrix,mat,result,dir,n,x,y);
                break;
            }
            case 2:{
                int i=x;
                int j=y;
                while(j>=0 && !mat[i][j]){
                    mat[i][j]=true;
                    result.push_back(matrix[i][j]);
                    j--;
                }
                x=i-1;
                y=j+1;
                dir++;
                solve(matrix,mat,result,dir,n,x,y);
                break;
            }
            case 3:{
                int i=x;
                int j=y;
                while(i>0 && !mat[i][j]){
                    mat[i][j]=true;
                    result.push_back(matrix[i][j]);
                    i--;
                }
                x=i+1;
                y++;
                dir=0;
                solve(matrix,mat,result,dir,n,x,y);
                break;
            }
        }
    }
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int dir=0;
        vector<vector<bool> > mat(matrix.size(),vector<bool>(matrix.at(0).size(),false));
        vector<int> result;
        solve(matrix,mat,result,dir,n,0,0);
        return result;
    }
    void print(vector<int> result){
        if(result.empty()){
            cout<<"Empty result"<<endl;
            return;
        }
        cout<<"\nResult : {"<<result.at(0);
        for(int i=1; i<result.size(); i++) cout<<","<<result.at(i);
        cout<<"}"<<endl;
    }
};
int main(){
    vector<vector<int> > matrix={{1,2,3},{4,5,6},{7,8,9}};
    Solution obj;
    vector<int> result=obj.spiralOrder(matrix);
    //cout<<endl<<"Final ";
    //obj.print(result);

}