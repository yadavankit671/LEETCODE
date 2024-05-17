#include<bits/stdc++.h>
using namespace std;
class Trie {
    private:
    vector<vector<string>>buffer;
    public:
    Trie():buffer(256){}
    
    void insert(string word) {
        buffer[word[0]].push_back(word);
    }
    
    bool search(string word) {
        if(find(buffer[word[0]].begin(),buffer[word[0]].end(),word)==buffer[word[0]].end()) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        if(buffer[prefix[0]].size()==0) return false;
        for(int i=0;i<buffer[prefix[0]].size();i++){
            if(buffer[prefix[0]].at(i).rfind(prefix,0)==0) return true; 
            // logic of rfind() is that it finds the index where the provided string starts && if that is zero then it is a prefix
        }
        return false;
    }
};
/*
["Trie","insert","search","search","startsWith","startsWith","insert","search","startsWith","insert","search","startsWith"]
[[],      ["ab"], ["abc"], ["ab"],    ["abc"],     ["ab"],     ["ab"],  ["abc"],  ["abc"],   ["abc"], ["abc"],   ["abc"]]
*/
int main(){
    Trie t;cout<<"null\t";
    t.insert("apple");cout<<"null\t";
    if(t.search("apple")) cout<<"true\t";else cout<<"false\t";
    if(t.search("app")) cout<<"true\t";else cout<<"false\t";
    if(t.startsWith("app")) cout<<"true\t";else cout<<"false\t";
    t.insert("app");cout<<"null\t";
    if(t.search("app")) cout<<"true\t";else cout<<"false\t";

}