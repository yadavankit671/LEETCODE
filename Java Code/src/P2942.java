import java.util.*;
class Solution2942 {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> result = new ArrayList<Integer>();
        for(int i=0;i<words.length;i++){
            if(words[i].indexOf(x)!=-1) result.add(i);
        }
        return result;
    }
}
public class P2942 {
    public static void main(String[] args) {
        Solution2942 obj= new Solution2942();
        String[] words=new String[]{"leet","code"};
        char c='e';
        List<Integer> result=obj.findWordsContaining(words, c);
        for(var x: result) System.out.print(x+",");
    }
}
