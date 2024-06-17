#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    string addition (string one, string two){
        string ans="";
        int carry=0;
        for(int i=one.length()-1,j=two.length()-1;i>=0||j>=0;i--,j--){
            int val=carry;
            if(i>=0) val+=one[i]-'0';
            if(j>=0) val+=two[j]-'0';
            ans=char(val%10+'0')+ans;
            carry=val/10;
        }
        if(carry) ans=char(carry+'0')+ans;
        return ans;
    }
    void Solve(string chota,string bada,string curr,int index,string &result){
        if(index<0) {
            result=curr;
            return;
        }
        long carry=0;
        string now="";
        for(int i=index;i<chota.length()-1;i++) now+='0';
        char mul=chota[index];
        for(int i=bada.length()-1;i>=0;i--){
            int val=(bada[i]-'0')*(mul-'0') +carry;
            now=char(val%10+'0')+now;
            val/=10;
            carry=val;
        }
        while(carry>0){
            now=char(carry%10+'0')+now;
            carry/=10;
        }
        if(curr.empty()) curr=now;
        else curr=addition(curr,now);
        Solve(chota,bada,curr,index-1,result);
    }
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        string chota,bada;
        if(num1.length()<num2.length()) chota=num1,bada=num2;
        else chota=num2,bada=num1;
        string result="";
        Solve(chota,bada,"",chota.length()-1,result);
        return result;
    }
};
int main(){
    string num1="9";
    string num2="9";
    Solution obj;
    cout<<"Result : "<<obj.multiply(num1,num2);
}