import java.util.List;
import java.util.ArrayList;
class Solution {
    public List<String> commonChars(String[] words) {
        List<String> result = new ArrayList<String>();
        int n=words.length;
        int[][] mat = new int[n][26];
        for(int i=0;i<n;i++){
            String word=words[i];
            for(int j=0;j<word.length();j++){
                mat[i][word.charAt(j)-'a']++;
            }
        }
        StringBuilder temp = new StringBuilder();
        for(int i=0;i<26;i++){
            int mini=Integer.MAX_VALUE;
            for(int j=0;j<n;j++){
                mini=Math.min(mini,mat[j][i]);
                if(mat[j][i]==0) break;
            }
            if(mini>0){
                char c= (char) ('a'+i);
                for(int j=0;j<mini;j++){
                    temp.append(c);
                }
            }
        }
        for(int i=0;i<temp.length();i++){
            result.add(Character.toString(temp.charAt(i)));
        }
        return result;
    }
}
public class P1002 {

}
