import java.util.*;

class Solution {
    public int minimumPushes(String word) {
        int result = 0;
        List<Integer> letterFreq = new ArrayList<>();
        for(int i = 0; i < 26; i++) letterFreq.add(0);
        for(int i = 0; i < word.length(); i++){
            int index = word.charAt(i) - 'a';
            letterFreq.set(index,letterFreq.get(index) + 1);
        }
        letterFreq.sort(Collections.reverseOrder());
        for(int i = 0; i < 26 ; i++){
            if(letterFreq.get(i) == 0) break;
            result += (i/8 + 1) * letterFreq.get(i);
        }
        return result;
    }
}
public class P3016 {
    public static void main(String[] args) {
        Solution obj = new Solution();
        int result = obj.minimumPushes("aabbccddeeffgghhiiiiii");
        System.out.println(result);
    }

}
