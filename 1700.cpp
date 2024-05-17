#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int z1=0;
        int z2=0;
        for(int i=0;i<students.size();i++){
            if(students.at(i)==0) z1++;
            if(sandwiches.at(i)==0) z2++;
        }
        if(z1==z2) return 0;
        int satisfied=0;
        int j=0;
        vector<bool> chk(students.size(),false);
        while(j<sandwiches.size()){
            int prev=j;
            int i=0;
            for(;i<students.size();i++){
                if(!chk.at(i) && students.at(i)==sandwiches.at(j)){
                    chk.at(i)=true;
                    satisfied++;
                    j++;
                }
            }
            if(prev==j) break;
            // take a boolean array for students check;
        }
        return students.size()-satisfied;
    }
};
int main(){
    vector<int> students ={1,1,1,0,0,1};
    vector<int> sandwiches={1,0,0,0,1,1};
    Solution obj;
    cout<<obj.countStudents(students,sandwiches)<<endl;
}