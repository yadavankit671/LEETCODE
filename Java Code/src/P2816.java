class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
class Solution2816{
    private static int solve(ListNode node){
        if(node==null) return 0;
        int carry=solve(node.next);
        int sum=node.val*2+carry;
        node.val=sum%10;
        carry=sum/10;
        return carry;
    }
    public ListNode doubleIt(ListNode head) {
        int carry=solve(head);
        while(carry>0) {
            head=new ListNode(carry%10,head);
            carry/=10;
        }
        return head;
    }
}
public class P2816 {
    public static void main(String[] args) throws Exception {
        ListNode head=new ListNode(9, new ListNode(0,new ListNode(1)));
        Solution2816 obj= new Solution2816();
        ListNode result=obj.doubleIt(head);
        System.out.print("\nResult : "+result.val);
        result=result.next;
        while(result!=null){
            System.out.print(","+result.val);
            result=result.next;
        }
    }
}
