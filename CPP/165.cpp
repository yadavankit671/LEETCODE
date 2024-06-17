#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    pair<int,int> solve(string version1,int index){
        int num=0;
        pair<int,int> result;
        while(index<version1.length()){
            if(version1[index]=='.') break;
            num=num*10+(version1[index]-'0');
            index++;
        }
        result.first=num;
        result.second=++index;
        return result;
    }
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        while(i<version1.length() || j<version2.length()){
            pair<int,int> one,two;
            one=solve(version1,i);
            two=solve(version2,j);
            i=one.second;
            j=two.second;
            if(one.first<two.first) return -1;
            else if(one.first>two.first) return 1;
        }
        return 0;
    }
};
int main(){

}
int main(){
    string s="7.5.2.4";
    string s2="7.5.3";
    Solution obj;
    cout<<obj.compareVersion(s,s2)<<endl;
}
/*

private: // 00001.00200.200
    void removerepeatdots(string &s){
        for ( int i=0;i<s.length()-1;){
            if(s[i]=='.' && s[i+1]=='.') {
                i++; // for example s="0001.00.00.1"
                while (i<s.length() && s[i]=='.') s.erase(s.begin()+i);
            }
            else i++;
        }
        if(s.at(s.length()-1)=='.') s.pop_back();
        if(s.at(0)=='.') s.insert(0,1,'0');
    }
    void removeleadingZeros(string &s){
        int i=0;
        while(i<s.length()){
            if(s[i]=='0'){
                s.erase(i,1);
            }
            else {
                while(i<s.length() && s[i]!='.'){
                    i++;
                }
                i++;
            }
        }
        removerepeatdots(s);
    }

*/