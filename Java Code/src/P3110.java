class Solution3110 {
    public int scoreOfString(String s) {
        int result = 0;
        for(int i=0;i<s.length()-1;i++){
            result+=Math.abs(s.charAt(i)-s.charAt(i+1));
        }
        return result;
    }
}
public class P3110 {
    public static void main(String[] args) {
        String s="hello";
        Solution3110 obj=new Solution3110();
        System.out.println(obj.scoreOfString(s));
    }
}
