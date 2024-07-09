class Solution {
    private int solve(TreeNode node,int target){
        if(node==null) return 0;
        if(node.left!=null && node.left.val==target && node.left.left==null && node.left.right==null) node.left=null;
        if(node.right!= null && node.right.val==target && node.right.right==null && node.right.left==null) node.right=null;
        int left=solve(node.left,target);
        int right=solve(node.right,target);
        return left+right+1;
    }
    public TreeNode removeLeafNodes(TreeNode root, int target) {
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
    static void traversal(TreeNode node){
        if(node == null) return;
        System.out.print(node.val+" ");
        traversal(node.left);
        traversal(node.right);
    }
    public static void main(String[] args) {
        TreeNode root=new TreeNode(1,new TreeNode(1,new TreeNode(1),null),new TreeNode(1,new TreeNode(1),new TreeNode(1)));
        Solution obj=new Solution();
        int target=1;
        TreeNode result=obj.removeLeafNodes(root, target);
        if(result==null ) System.out.println("NULL");
        traversal(result);
    }
}
