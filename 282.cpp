#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void BackTracking(string num,int target,int index,long curr,long prev,string oper,vector<string> &result){
        if(curr==target && index==num.length()) {
            result.push_back(oper);
            return;
        }
        string number="";
        long value=0;
        if(index>=num.length()) return;
        for(int i=index;i<num.length();i++){
            if (i > index && num[index] == '0') break;
            number +=num[i];
            value=value*10+(num[i]-'0');
            if(index==0){
                BackTracking(num,target,i+1,value,value,number,result);
            }
            else{
                BackTracking(num,target,i+1,curr+value,value,oper+"+"+number,result);
                BackTracking(num,target,i+1,curr-value,-value,oper+"-"+number,result);
                BackTracking(num,target,i+1,curr-prev+(prev*value),prev*value,oper+"*"+number,result);
            }
        }
    }
    public:
    vector<string> addOperators(string num,int target){
        if(num.empty()) return {};
        ios_base::sync_with_stdio(false);
        vector<string> result;
        BackTracking(num,target,0,0,0,"",result);
        return result;
    }
};

int main(){
    string num="105";
    int target=5;
    Solution obj;
    vector<string> res=obj.addOperators(num,target);
    for(string x: res) cout<<x<<",";
}
/*
I didn't read the question properly and thought that we are performing operations on single digit only so I wrote this crap: :-(

    class Solution {
    private: 
    void solve(string num,int index,int target,vector<string> &result, int curr,string op){
        if(curr==target){
            result.push_back(op);
            return;
        }
        if(index>=num.length()) return;
        int temp1=curr+(num[index]-'0');
        string tempX=op+'+'+num[index];
        int temp2=curr-(num[index]-'0');
        string tempY=op+'-'+num[index];
        int temp3=curr;
        string tempZ=op+'*'+num[index];
        if(index<2)
        temp3*=(num[index]-'0');
        else {
            if(op.at(op.length()-2)!='*'){
                if(op.at(op.length()-2)=='+'){
                    temp3-=(num[index-1]-'0');
                    temp3+=((num[index-1]-'0')*(num[index]-'0'));
                }
                else{
                    temp3+=(num[index-1]-'0');
                    temp3-=(num[index-1]-'0')*(num[index]-'0');
                }
            }
            else temp3*=(num[index]-'0');
        }
        solve(num,index+1,target,result,temp1,tempX);
        solve(num,index+1,target,result,temp2,tempY);
        solve(num,index+1,target,result,temp3,tempZ);
    }
    public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string temp="";
        temp+=num[0];
        solve(num,1,target,result,num[0]-'0',temp);
        return result;
    }
};
*/