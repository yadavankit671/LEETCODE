import java.util.*;
class Solution {
    private void reverse (StringBuilder sb,int start,int end){
        while(start<end){
            char temp = sb.charAt(end);
            sb.setCharAt(end,sb.charAt(start));
            sb.setCharAt(start, temp);
            start++;
            end--;
        }
    }
    public String reverseParentheses(String s) {
        StringBuilder sb = new StringBuilder(s);
        Stack<Integer> st = new Stack<>();
        int index = 0;
        while(index < sb.length()){
            if (sb.charAt(index) == '(') {
                sb.deleteCharAt(index);
                st.push(index);
            } 
            else if (sb.charAt(index) == ')') {
                int start = st.pop();
                int end = index;
                sb.deleteCharAt(end); 
                reverse(sb, start, end-1);
            } 
            else index++;
        }
        return sb.toString();
    }
}
public class P1190 {
    public static void main(String[] args) {
        Solution obj= new Solution();
        String s="(ed(et(oc))el)";
        System.out.println(obj.reverseParentheses(s));
    }
}
