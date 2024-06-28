public class P206 {
    static ListNode reverseList(ListNode head) {
        ListNode rev=null;
        while(head !=null){
            ListNode temp=head.next;
            head.next=rev;
            rev=head;
            head=temp;
        }
        return rev;
    }
    static void print(ListNode head){
        if(head==null){
            System.out.println("Empty List");
            return;
        }
        System.out.print("List : "+head.val);
        head=head.next;
        while(head !=null){
            System.out.print("-->"+head.val);
            head=head.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        ListNode head=null;
        for(int i=10;i>0;i--){
            head=new ListNode(i,head);
        }
        print(head);
        ListNode rev=reverseList(head);
        print(rev);
    }
}
