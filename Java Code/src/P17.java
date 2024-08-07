import java.util.*;
class Solution {
    private void permute(int index,int len, StringBuilder temp, String digits,String[] dictonary,List<String> result){
        if(index >= len){
            result.add(temp.toString());
            return;
        }
        String letter = dictonary[digits.charAt(index) - '0'];
        for(int i = 0; i < letter.length(); i++){
            temp.append(letter.charAt(i));
            permute(index + 1, len, temp, digits, dictonary, result);
            temp.deleteCharAt(temp.length() - 1);
        }
    }
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        String[] dictonary = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int len = digits.length();
        if(len == 0) return result;
        StringBuilder temp = new StringBuilder();
        permute(0,len,temp,digits,dictonary, result);
        return result;
    }
}
public class P17 {
    public static void main(String[] args) {
        Solution obj = new Solution();
        List<String> result = obj.letterCombinations("23");
        System.out.println(result.toString());
    }
}
