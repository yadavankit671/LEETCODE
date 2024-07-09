class TrieNode{
    TrieNode[] children;
    boolean isEndOfWord;
    TrieNode(){
        children = new TrieNode[26];
        isEndOfWord=false;
    }
}
class Trie {
    private TrieNode root;
    public Trie() {
        root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode currNode = root;
        for(char ch : word.toCharArray()){
            int index = ch-'a';
            if(currNode.children[index]==null){
                currNode.children[index]= new TrieNode();
            }
            currNode = currNode.children[index];
        }
        currNode.isEndOfWord=true;
    }
    
    public boolean search(String word) {
        TrieNode currNode = root;
        for(char ch : word.toCharArray()){
            int index = ch-'a';
            if(currNode.children[index]==null) return false;
            currNode=currNode.children[index];
        }
        return currNode.isEndOfWord;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode currNode=root;
        for(char ch : prefix.toCharArray()){
            int index = ch-'a';
            if(currNode.children[index]==null) return false;
            currNode = currNode.children[index];
        }
        return true;
    }
}
public class P208 {

}
