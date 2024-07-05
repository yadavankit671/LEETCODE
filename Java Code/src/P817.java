import java.util.*;
public class P817 {
    public int numComponents(ListNode head, int[] nums) {
        int result=0;
        Set<Integer> buff= new HashSet<>();
        for(int x: nums) buff.add(x);
        while(head!=null){
            if(buff.contains(head.val) && (head.next==null ||!buff.contains(head.next.val))){
                result++;
            }
            head=head.next;
        }
        return result;
    }
}
