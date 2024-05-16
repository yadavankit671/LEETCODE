class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
class Solution2331 {
    private boolean solve(boolean left,boolean right,int val){
        if(val==2) {
            if(!left && !right) return false;
            return true;
        }
        if(left && right) return true;
        return false;
    }
    private boolean traverse(TreeNode node){
        if(node.val<2){
            return node.val==1;
        }
        if(node.left!=null && node.right!=null && node.left.val<2 && node.right.val<2){
            boolean left=(node.left.val==1) ? true: false;
            boolean right=(node.right.val==1) ? true: false;
            return solve(left,right,node.val);
        }
        else if(node.left!=null && node.left.val<2){
            boolean right=traverse(node.right);
            boolean left=(node.left.val==1) ? true: false;
            return solve(left,right,node.val);
        }
        else if(node.right!=null && node.right.val<2){
            boolean left=traverse(node.left);
            boolean right=(node.right.val==1) ? true: false;
            return solve(left,right,node.val);
        }
        boolean left=traverse(node.left);
        boolean right=traverse(node.right);
        return solve(left,right,node.val);
    }
    public boolean evaluateTree(TreeNode root) {
        if(root.left==null && root.right==null) return root.val==1;
        return traverse(root);
    }
}
public class P2331 {
    public static void main(String[] args) {
        TreeNode root=new TreeNode(3,new TreeNode(3,new TreeNode(0),new TreeNode(0)),new TreeNode(2,new TreeNode(3,new TreeNode(1),new TreeNode(3,new TreeNode(2,new TreeNode(1),new TreeNode(1)),new TreeNode(1))),new TreeNode(2,new TreeNode(1),new TreeNode(1))));
        Solution2331 obj=new Solution2331();
        System.out.println(obj.evaluateTree(root));
    }
}
