class TreeNode1325 {
    int val;
    TreeNode1325 left;
    TreeNode1325 right;
    TreeNode1325() {}
    TreeNode1325(int val) { this.val = val; }
    TreeNode1325(int val, TreeNode1325 left, TreeNode1325 right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
class Solution1325 {
    private int solve(TreeNode1325 node,int target){
        if(node==null) return 0;
        if(node.left!=null && node.left.val==target && node.left.left==null && node.left.right==null) node.left=null;
        if(node.right!= null && node.right.val==target && node.right.right==null && node.right.left==null) node.right=null;
        int left=solve(node.left,target);
        int right=solve(node.right,target);
        return left+right+1;
    }
    public TreeNode1325 removeLeafNodes(TreeNode1325 root, int target) {
        int totalnodes=Integer.MAX_VALUE;
        int newCount=0;
        while(newCount!=totalnodes){
            totalnodes=newCount;
            newCount=solve(root, target);
        }
        if(root.left==null && root.right==null && root.val==target) return null;
        return root;
    }
}
public class P1325 {
    static void traversal(TreeNode1325 node){
        if(node == null) return;
        System.out.print(node.val+" ");
        traversal(node.left);
        traversal(node.right);
    }
    public static void main(String[] args) {
        TreeNode1325 root=new TreeNode1325(1,new TreeNode1325(1,new TreeNode1325(1),null),new TreeNode1325(1,new TreeNode1325(1),new TreeNode1325(1)));
        Solution1325 obj=new Solution1325();
        int target=1;
        TreeNode1325 result=obj.removeLeafNodes(root, target);
        if(result==null ) System.out.println("NULL");
        traversal(result);
    }
}
