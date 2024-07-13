import java.util.*;
class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        List<Integer> result = new ArrayList<Integer>();
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < positions.length; i++)
            indices.add(i);
        Comparator<Integer> cmp = (a, b) -> {
            return positions[a] - positions[b];
        };
        indices.sort(cmp);
        Stack<Integer> st = new Stack<>();
        for (int index : indices) {
            if (directions.charAt(index) == 'R') {
                st.add(index);
            } else {
                if (st.isEmpty()) continue;
                while (!st.isEmpty() && healths[st.peek()] <= healths[index] && healths[index] > 0) {
                    if (healths[st.peek()] == healths[index]) {
                        healths[index] = -1;
                        healths[st.peek()] = -1;
                        st.pop();
                        break;
                    } else {
                        healths[st.peek()] = -1;
                        st.pop();
                        healths[index]--;
                    }
                }
                if (!st.isEmpty() && healths[index] > 0 && healths[st.peek()] > healths[index]) {
                    healths[st.peek()]--;
                    healths[index] = -1;
                }
            }
        }
        for (int health : healths) {
            if (health > 0) result.add(health);
        }
        return result;
    }
}
/*
example 1 :
positions = [1,2,5,6]
healths = [10,10,11,11]
directions = "RLRL"

example 2 :
positions = [3,5,2,6]
healths = [10,10,15,12]
directions = "RLRL"

example 3 : 
positions = [34,50,42,2]
healths = [6,27,17,38]
directions = "LLRR"
 */
public class P2751 {
    public static void main(String[] args) {
        int[] positions = {34,50,42,2};
        int [] healths ={6,27,17,38};
        String directions = "LLRR";
        Solution obj = new Solution();
        System.out.println(obj.survivedRobotsHealths(positions, healths, directions).toString());
    }
}
