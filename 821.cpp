#include<bits/stdc++.h>
using namespace std;
void print(vector<int> result){
    if(result.size()==0){
        cout<<"Empty List"<<endl;
        return ;
    }
    cout<<"List : ["<<result.at(0);
    for(int i=1;i<result.size();i++) cout<<","<<result.at(i);
    cout<<"]"<<endl;
}
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> result;
        for(int i=0; i<s.length();i++){
            int start=max(i-1,0);
            int end=min<int>(i+1,s.length()-1);
            if(s[i]!=c)
            while(start>=0 || end<s.length()){
                if(s[start]==c){
                    result.push_back(abs(i-start));
                    break;
                }
                else if(s[end]==c){
                    result.push_back(abs(i-end));
                    break;
                }
                else {
                    start=max(start-1,0);
                    end=min<int>(end+1,s.length()-1);
                }
            }
            else result.push_back(0);
        }
        return result;
    }
};
int main(){
    string str="loveleetcode";
    char c='e';
    Solution obj;
    vector<int> result=obj.shortestToChar(str,c);
    print(result);//3,2,1,0,1,0,0,1,2,2,1,0
}