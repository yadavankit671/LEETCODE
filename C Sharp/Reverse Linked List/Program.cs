namespace revLinkedList{
    public class ListNode {
        public int val;
        public ListNode next;
        public ListNode(int val=0, ListNode next=null) {
            this.val = val;
            this.next = next;
        }
    }

    public class Solution {
        public ListNode ReverseList(ListNode head) {
            if (head is null) return null;
            if (head.next is null) return head;
            ListNode result=new ListNode(head.val,null);
            head=head.next;
            while(head is not null){
                ListNode temp=new ListNode(head.val,null);
                temp.next=result;
                result=temp;
                head=head.next;
            }
            return result;
        }
    }
}