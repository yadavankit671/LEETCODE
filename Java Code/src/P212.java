import java.util.*;
class TrieNode{
    TrieNode[] children;
    String word;
    TrieNode(){
        children = new TrieNode[26];
        word = null;
    }
}
class Trie{
    TrieNode root;
    Trie(){
        root = new TrieNode();
    }
    void insert(String word){
        TrieNode curr = root;
        for(char ch : word.toCharArray()){
            int index = ch-'a';
            if(curr.children[index]==null) curr.children[index] = new TrieNode();
            curr=curr.children[index];
        }
        curr.word=word;
    }
}
class Solution{
    public List<String> findWords(char[][] board,String[] words){
        List<String> result = new ArrayList<>();
        Trie trie = new Trie();
        for(String word : words){
            trie.insert(word);
        }
        int n= board.length, m= board[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board,trie.root,i,j,result);
            }
        }
        return result;
    }

    private void dfs(char[][] board, TrieNode node, int i, int j, List<String> result) {
        if(i<0 || i>=board.length || j<0 || j>=board[0].length) return;
        char ch = board[i][j];
        if(ch == '#' || node.children[ch-'a']==null) return;
        node = node.children[ch-'a'];
        if(node.word!=null) {
            result.add(node.word);
            node.word=null;
        }
        board[i][j]='#';
        dfs(board,node,i-1,j,result);
        dfs(board,node,i+1,j,result);
        dfs(board,node,i,j-1,result);
        dfs(board,node,i,j+1,result);
        board[i][j]=ch;
    }
}


public class P212{

}