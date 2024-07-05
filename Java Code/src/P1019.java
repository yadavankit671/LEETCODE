import java.util.*;

public class P1019 {
    public int[] nextLargerNodes(ListNode head) {
        List<Integer> nodes=new ArrayList<>();
        while(head!=null){
            nodes.add(head.val);
            head=head.next;
        }
        int[] result=new int[nodes.size()];
        Stack<Integer> s= new Stack<>();
        for (int i = nodes.size() - 1; i >= 0; i--) { 
            if (!s.isEmpty()) {
                while (!s.isEmpty() && s.peek() <= nodes.get(i)) {
                    s.pop();
                }
            }
            result[i] = s.isEmpty() ? 0 : s.peek();
            s.push(nodes.get(i)); 
        } 
        return result;
    }
}
