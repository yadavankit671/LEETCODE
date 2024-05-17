#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        vector<pair<int,int>> freq;
        string temp=" ";
        for(int i=0;i<s.length();i++){
            if(s.at(i)!=temp.back()){
                temp.push_back(s[i]);
            }
            else {
                int start=i;
                int count=1;
                while(i<s.length() && s.at(i)==temp.back()) {
                    count++;
                    i++;
                }
                string x="";
                while(count>0){
                    x=char(count%10+'0')+x;
                    count/=10;
                }
                temp+=x;
                freq.push_back(make_pair(count,start));
                i--;
            }
        }
        if(k==0) return temp.size()-1;
        sort(freq.begin(),freq.end(),[](pair<int,int> &a,pair<int,int> &b){return a.first<b.first;});
        for(int i=freq.size()-1;i>=0;i--){
            if(k==freq.at(i).first){
                int count=0;
                // wrong approach
            }
        }
    }
};
int main(){
    string s = "aaaaaaaaaaa";
    int k=0;
    Solution obj;
    cout<<obj.getLengthOfOptimalCompression(s,k)<<endl;
}