#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int> > &mat){
    if(mat.empty()){
        cout<<"empty"<<endl;
        return;
    }
    cout<<"mat Table : "<<endl<<"{";
    for(vector<int> arr : mat){
        cout<<"{"<<arr[0];
        for(int i=1;i<arr.size();i++){
            cout<<","<<arr[i];
        }
        cout<<"}"<<endl;
    }
    cout<<"}"<<endl;
    return;
}
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<vector<int> > mat(n,vector<int>(26,0));
        for(int i=0;i<words.size();i++){
            string word=words[i];
            for (char c :word){
                mat[i][c-'a']++;
            }
        }
        vector<string> ans;
        string temp="";
        for(int i=0;i<26;i++){
            int mini=INT_MAX;
            for(int j=0;j<n;j++){
                mini=min(mini,mat[j][i]);
            }
            temp.append(mini,'a'+i);
        }
        for(char c : temp) ans.push_back(string(1,c));
        return ans;
    }
};
int main(){
    vector<string> words={"bella","label","roller"};
    Solution obj;
    vector<string> res=obj.commonChars(words);
    for(string x : res) cout<<x<<",";
}