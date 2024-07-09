class Solution {
    ListNode reverseList(ListNode head) {
        ListNode rev=null;
        while(head !=null){
            ListNode temp=head.next;
            head.next=rev;
            rev=head;
            head=temp;
        }
        return rev;
    }
    void print(ListNode head){
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

}
public class P206{
    public static void main(String[] args) {
        Solution obj=new Solution();
        ListNode head=null;
        for(int i=10;i>0;i--){
            head=new ListNode(i,head);
        }
        obj.print(head);
        ListNode rev=obj.reverseList(head);
        obj.print(rev);
    }
}