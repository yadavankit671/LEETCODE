// class TreeNode {
//     int val;
//     TreeNode left;
//     TreeNode right;
//     TreeNode() {}
//     TreeNode(int val) { this.val = val; }
//     TreeNode(int val, TreeNode left, TreeNode right) {
//         this.val = val;
//         this.left = left;
//         this.right = right;
//     }
// }
class Solution {
    private int sum;
    private void solve(TreeNode node){
        if(node==null) return;
        solve(node.right);
        node.val+=sum;
        sum=node.val;
        solve(node.left);
    }
    public TreeNode bstToGst(TreeNode root) {
        sum=0;
        solve(root);
        return root;
    }
}
