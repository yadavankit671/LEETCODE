class Solution {
    private ListNode reverse(ListNode node){
        ListNode rev=null;
        while(node!=null){
            ListNode temp=node;
            node=node.next;
            temp.next=rev;
            rev=temp;
        }
        return rev;
    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result=null;
        l1=reverse(l1);
        l2=reverse(l2);
        int carry=0;
        while(l1!=null && l2!=null){
            int sum=l1.val+l2.val+carry;
            carry=sum/10;
            ListNode temp=new ListNode(sum%10);
            temp.next=result;
            result=temp;
            l1=l1.next;
            l2=l2.next;
        }
        while(l1!=null){
            int sum=l1.val+carry;
            carry=sum/10;
            ListNode temp=new ListNode(sum%10);
            temp.next=result;
            result=temp;
            l1=l1.next;
        }
        while(l2!=null){
            int sum=l2.val+carry;
            carry=sum/10;
            ListNode temp=new ListNode(sum%10);
            temp.next=result;
            result=temp;
            l2=l2.next;
        }
        return result;
    }
}
