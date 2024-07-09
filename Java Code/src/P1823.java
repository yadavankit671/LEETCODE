public class P1823 {
    private ListNode head;
    private ListNode tail;
    void initialise(int n){
        head= new ListNode(-1);
        ListNode prev= head;
        for(int i=1;i<=n;i++){
            ListNode temp= new ListNode(i);
            prev.next=temp;
            prev=temp;
        }
        head=head.next;
        prev.next=head;
        tail=prev;
    }
    int solve(int n,int k){
        if(k==1) return tail.val;
        ListNode start=head;
        ListNode prev=null;
        while(n!=1){
            int t=k-1;
            while(t>0){
                prev=start;
                start=start.next;
                t--;
            }
            if(start.next==head){
                prev.next=head;
                start=head;
            }
            else if(start==head){
                start=head.next;
                prev.next=head.next;
                head=head.next;
            }
            else{
                start=start.next;
                prev.next=start;
            }
            n--;
        }
        return start.val;
    }
    public int findTheWinner(int n, int k) {
        initialise(n);
        return solve(n,k);
    }
    public static void main(String[] args) {
        P1823 obj=new P1823();
        System.out.println(obj.findTheWinner(6, 5));
    }
}
