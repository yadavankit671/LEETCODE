#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    TrieNode *children[26];
    bool isEndOfWord;
    TrieNode(){
        isEndOfWord = false;
        for(int i=0; i<26; i++)
            children[i] = nullptr;
    }
};
class Trie {
    private : 
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *currNode = root;
        for(char ch : word){
            int index = ch-'a';
            if(currNode->children[index]==nullptr){
                currNode->children[index]= new TrieNode();
            }
            currNode=currNode->children[index];
        }
        currNode->isEndOfWord=true;
    }
    
    bool search(string word) {
        TrieNode *currNode = root;
        for(char ch : word){
            int index = ch-'a';
            if(currNode->children[index]==nullptr) return false;
            currNode=currNode->children[index];
        }
        return currNode->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *currNode = root;
        for(char ch : prefix){
            int index = ch-'a';
            if(currNode->children[index]==nullptr) return false;
            currNode=currNode->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
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