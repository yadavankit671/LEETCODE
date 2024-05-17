
public class App {
    private static int solve(ListNode node){
        if(node==null) return 0;
        int carry=solve(node.next);
        int sum=node.val*2+carry;
        node.val=sum%10;
        carry=sum/10;
        return carry;
    }
    public static ListNode doubleIt(ListNode head) {
        int carry=solve(head);
        while(carry>0) {
            head=new ListNode(carry%10,head);
            carry/=10;
        }
        return head;
    }
    public static void main(String[] args) throws Exception {
        ListNode head=new ListNode(9, new ListNode(0,new ListNode(1)));
        ListNode result=doubleIt(head);
        System.out.print("\nResult : "+result.val);
        result=result.next;
        while(result!=null){
            System.out.print(","+result.val);
            result=result.next;
        }
    }
}
