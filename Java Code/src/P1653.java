class Solution{
    public int minOperations(String s){
        int result = 0;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == 'b') count++;
            else if (count > 0) {
                result++;
                count--;
            }
        }
        return result;
    }
}
public class P1653 {

}
