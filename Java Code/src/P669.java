class Solution {
    private TreeNode solve(TreeNode node, int low, int high){
        if(node==null) return null;
        if(node.val<low) node=solve(node.right, low, high);
        else if(node.val>high) node=solve(node.left, low,high);
        else {
            node.left=solve(node.left, low, high);
            node.right=solve(node.right, low, high);
        }
        return node;
    }
    public TreeNode trimBST(TreeNode root, int low, int high) {
        root=solve(root, low, high);
        return root;
    }
}
