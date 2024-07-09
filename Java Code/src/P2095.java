class Solution {
    private int len(ListNode head){
        int ret=0;
        while(head!=null){
            ret++;
            head=head.next;
        }
        return ret;
    }
    public ListNode deleteMiddle(ListNode head) {
        if(head.next==null) return null;
        int length=len(head);
        length/=2;
        ListNode temp=head;
        while(length!=1){
            length--;
            temp=temp.next;
        }
        temp.next=temp.next.next;
        return head;
    }
}
