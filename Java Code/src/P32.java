import java.util.*;
class Solution {
    public int longestValidParentheses(String s) {
        int result = 0;
        List<Integer> indices = new ArrayList<>();
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '(') indices.add(i);
            else{
                if(!indices.isEmpty() && s.charAt(indices.getLast()) == '(')
                    indices.removeLast();  // valid pair
                else indices.add(i);
            }
        }
        if(indices.isEmpty()) return s.length();
        result = indices.get(0);
        for(int i = 1; i < indices.size(); i++){
            result = Math.max(result, indices.get(i) - indices.get(i - 1) - 1);
        }
        result = Math.max(result, s.length() - indices.getLast() - 1);
        return result;
    }
}
public class P32 {

}
