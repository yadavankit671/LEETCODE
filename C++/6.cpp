#include<bits/stdc++.h>
using namespace std;
/*
1                  9                      17
2             8    10               16   18                24
3       7          11         15         19          23 
4   6              12   14               20    22
5                 13                    21
*/
void print(vector<vector<char>> buffer){
    if(buffer.size() == 0){
        cout<<"Empty List "<<endl;
        return;
    }
    for(int i=0;i<buffer.size();i++){
        for(int j=0;j<buffer.at(i).size();j++){
            if(buffer.at(i).at(j)=='0') cout<<"  ";
            else
            cout<<" "<<buffer.at(i).at(j);
        }
        cout<<endl;
    }
}
class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        vector<vector<char>> buffer(numRows,vector<char>(s.length(),'0'));
        int i=0,k=0,col=0;
        while(k<s.length()) {
            while(i<numRows){
                if(k>=s.length()) break;
                buffer[i++][col]=s[k++];
            }
            col++;i-=2;
            while(i>0){
                if(k>=s.length()) break;
                buffer[i--][col++]=s[k++];
            }
            i=0;
        }
        for(int i=0;i<buffer.size();i++) {
            for(int j=0;j<buffer.at(i).size();j++){
                if(buffer[i][j]!='0')result+=buffer[i][j];
            }
        }
        return result;
    }
};
int main(){
    string str="PAYPALISHIRING";
    Solution obj;
    int numRows =3;
    cout<<obj.convert(str,numRows);
}