public class P1367 {
    private boolean check(TreeNode node,ListNode curr){
        if(curr==null) return true;
        if(node==null) return false;
        if(node.val!=curr.val) return false;
        return check(node.left,curr.next) | check(node.right,curr.next);
    }
    private boolean solve(TreeNode node,ListNode head){
        if(node==null) return false;
        if(node.val==head.val){
            if(check(node,head)) return true;
        }
        return solve(node.left,head) | solve(node.right,head);
    }
    public boolean isSubPath(ListNode head, TreeNode root) {
        return solve(root,head);
    }
}
