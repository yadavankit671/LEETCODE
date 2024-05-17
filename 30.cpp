#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool check(map<string,int> buffer,string & temp,int wordlen,vector<string> words,int buffer_size){
        for(int i=0;i<temp.length();i+=wordlen){
            string t=temp.substr(i,wordlen);
            if(buffer.find(t)!=buffer.end()){
                if(--buffer[t]==-1) return false;
            }
            else return false;
        }
        return true;
    }
    public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> buffer;
        vector<int> result;
        int wordlen=words.at(0).length();
        int length=wordlen*words.size();
        for(auto x: words) buffer[x]++;
        int buffersize=buffer.size();
        for(int i=0;i<s.length();i++){
            string temp=s.substr(i,wordlen);
            if(i+length>s.length()) break;
            else if(find(words.begin(),words.end(),temp)!=words.end()){
                string temp2=s.substr(i,length);
                if(check(buffer,temp2,wordlen,words,buffersize))result.push_back(i);
            }
            else continue;
        }
        return result;
    }
};
int main(){
    vector<string> words={"foo","bar"};
    string s="barfoothefoobarman";
    Solution obj;
    vector<int> result=obj.findSubstring(s,words);
    cout<<endl;
    for(auto x:result) cout<<x<<",";
}