import java.util.*;
class Solution {
    public int[] finalPrices(int[] prices) {
        Stack<Integer> st = new Stack<>();
        int index = prices.length - 1;
        while(index>=0){
            int curr = prices[index];
            while(!st.isEmpty() && st.peek()>curr){
                st.pop();
            }
            prices[index--] -= st.isEmpty() ? 0 : st.peek();
            st.push(curr);
        }
        return prices;
    }
}
public class P1475 {

}
