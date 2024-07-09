class Solution {
    public int longestPalindrome(String s) {
        int result=0;
        int[] buff = new int[266];
        for (int i=0;i<s.length();i++) buff[s.charAt(i)]+=1;
        int x=0;
        for(int i=0;i<buff.length;i++){
            if(buff[i]>0){
                if(buff[i]%2==0){
                    result+=buff[i];
                }
                else {
                    x=1;
                    result+=buff[i]-1;
                }
            }
        }
        return (x==0)? result: result+1;
    }
}
public class P409 {
    public static void main(String[] args) {
        String s="abccccdd";
        Solution obj=new Solution();
        System.out.println(obj.longestPalindrome(s));
    }
}
