public class P2058 {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        if(head.next==null) return new int[]{-1,-1};
        int firstCritical=Integer.MAX_VALUE;
        int lastCritical=Integer.MAX_VALUE;
        int minDist=Integer.MAX_VALUE;
        int prev=head.val;
        int index=1;
        int[] res= {-1,-1};
        while(head!=null){
            if(head.next!=null && ((head.val>prev && head.val>head.next.val)||(head.val<prev && head.val<head.next.val))){
                if(firstCritical==Integer.MAX_VALUE) firstCritical=index;
                minDist=Math.min(minDist,Math.abs(index-lastCritical));
                lastCritical=index;
            }
            index++;
            prev=head.val;
            head=head.next;
        }
        if(firstCritical==lastCritical) return res;
        res[1]=lastCritical-firstCritical;
        res[0]=Math.min(minDist,res[1]);
        return res;
    }
}
