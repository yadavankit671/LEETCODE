#include<bits/stdc++.h>
using namespace std;
class MagicDictionary {
    private:
    map<int,string> keys;
    bool match(string searchWord, string s,int start,int end){
        if(start>=end) {return false;}
        string sub= s.substr(start,searchWord.length());
        if(sub==searchWord) return match(searchWord,s,start+sub.length(),end);
        bool found = false;
        int count = 0;
        for(int i=0;i<searchWord.length();i++){
            if(searchWord[i]!=sub.length()) count++;
            if(count>1) break;
        }
        if(count==1) return true;
        if(found==false) found=match(searchWord,s,start+sub.length(),end);
        return found; 
    }
    public:
    MagicDictionary() {
        keys.clear();
    }
    void buildDict(vector<string> dictionary) {
        for(auto itr: dictionary){
            int len=itr.length();
            if(keys.find(len)!=keys.end()){
                keys[len]+=itr;
            }
            else keys[len]=itr;
        }
    }
    bool search(string searchWord) {
        int len=searchWord.length();
        if(keys.find(len)==keys.end()) return false;
        return match(searchWord,keys[len],0,keys[len].length());
    }
};
// ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
// [[], [["pello","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
// cout<<char(i+'a')<<"\t"<<srchf[i]<<"\t"<<subf[i]<<endl;

int main(){
    MagicDictionary obj;
    obj.buildDict({"pello","leetcode"});
    cout<<obj.search("hello")<<endl;
    cout<<obj.search("hhello");

}