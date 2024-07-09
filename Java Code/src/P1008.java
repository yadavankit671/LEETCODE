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
class Solution {
    private void buildTree(int[] preorder,int i,int j,TreeNode parent){
        if(parent==null) return;
        if(i>j || i>=preorder.length || j>=preorder.length) return;
        int right=i;
        for(int k=i;k<=j;k++){
            if(preorder[k]>parent.val){
                right=k;
                break;
            }
        }
        if(preorder[i]<parent.val) parent.left=new TreeNode(preorder[i]);
        if(preorder[right]>parent.val) parent.right=new TreeNode(preorder[right]);
        buildTree(preorder, i+1, (right!=i)?right-1:j,parent.left);
        buildTree(preorder,(right==i)?i+1:right+1, j, parent.right);
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root=new TreeNode(preorder[0]);
        buildTree(preorder, 1, preorder.length-1, root);
        return root;
    }
}
public class P1008 {
    public static void main(String[] args) {
        
    }
}
