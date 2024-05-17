namespace GCD{
    public class ListNode {
        public int val;
        public ListNode next;
        public ListNode(int val=0, ListNode next=null) {
            this.val = val;
            this.next = next;
        }
    }
    public class Solution {
        public static int GCD(int p, int q){
            if(q == 0){
                return p;
            }
            return GCD(q, p%q);
        }
        public ListNode InsertGreatestCommonDivisors(ListNode head) {
            if(head.next is null) return head;
            ListNode temp=head;
            while(temp.next.next is not null){
                int res=GCD(4,5);
                ListNode newNode=new ListNode(GCD(temp.val,temp.next.val),temp.next);
                temp.next=newNode;
                temp=temp.next.next;
            }
            ListNode newNode1=new ListNode(GCD(temp.val,temp.next.val),temp.next);
            temp.next=newNode1;
            return head;
        }
    }
    public class Program{
        public static void Main(string[] args)
        {
            Solution s=new Solution();
            ListNode ip3=new ListNode(3);
            ListNode ip10=new ListNode(10,ip3);
            ListNode ip8=new ListNode(8,ip10);
            ListNode head=new ListNode(18,ip8);
            ListNode res=s.InsertGreatestCommonDivisors(head);
            //18,8,10,3
            Console.Write("Result List : "+res.val);
            res=res.next;
            while(res is not null){
                Console.Write("-->"+res.val);
                res=res.next;
            }
        }
    }
}