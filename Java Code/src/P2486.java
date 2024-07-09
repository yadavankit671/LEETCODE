class Solution {
    public int appendCharacters(String s, String t) {
        int j=0;
        int covered=0;
        for(int i=0;i<s.length();i++){
            if(j>=t.length()) break;
            if(s.charAt(i)==t.charAt(j)) {
                covered++;
                j++;
            }
        }
        return t.length()-covered;
    }
}
public class P2486 {

}
