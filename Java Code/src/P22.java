import java.util.ArrayList;
import java.util.List;
class Solution {
    private void BackTracking(List<String> result,StringBuilder curr,int open,int close,int n){
        if(curr.length()==2*n ){
            result.add(curr.toString());
            return;
        }
        if(open<n){
            curr.append("(");
            BackTracking(result,curr,open+1,close,n);
            curr.deleteCharAt(curr.length()-1);
        }
        if(close<open){
            curr.append(")");
            BackTracking(result,curr,open,close+1,n);
            curr.deleteCharAt(curr.length()-1);
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> result= new ArrayList<>();
        StringBuilder curr = new StringBuilder();
        BackTracking(result, curr, 0, 0, n);
        return result;
    }
}
public class P22{
    public static void main(String[] args) {
        int n=5;
        Solution obj = new Solution();
        List<String> result = obj.generateParenthesis(n);
        for(String s: result) System.out.println(s);
    }
}
