#include<bits/stdc++.h>
using namespace std;
void print(vector<string> result){
    if(result.size()==0){
        cout<<"Empty List !!"<<endl;
        return;
    }
    cout<<"List : "<<result.at(0);
    for(int i=1;i<result.size();i++){
        cout<<","<<result[i];
    }
    cout<<endl;
}
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;
        for(int i=0;i<words.size();i++){
            int start=0;
            string temp="";
            for(int j=0;j<words.at(i).length();j++){
                if(words.at(i).at(j)==separator){
                    temp=words.at(i).substr(start,j-start);
                    if(temp.length()!=0) result.push_back(temp);
                    start=j+1;
                }
            }
            temp=words.at(i).substr(start,words.at(i).length());
            if(temp.length()!=0) result.push_back(temp);
        }
        return result;
    }
};
int main(){
    vector<string> words={"|||"};
    char separator='|';
    Solution obj;
    vector<string> result=obj.splitWordsBySeparator(words,separator);
    print(result);
}