class TreeNode1008 {
    int val;
    TreeNode1008 left;
    TreeNode1008 right;
    TreeNode1008() {}
    TreeNode1008(int val) { this.val = val; }
    TreeNode1008(int val, TreeNode1008 left, TreeNode1008 right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
class Solution1008 {
    private void buildTree(int[] preorder,int i,int j,TreeNode1008 parent){
        if(parent==null) return;
        if(i>j || i>=preorder.length || j>=preorder.length) return;
        int right=i;
        for(int k=i;k<=j;k++){
            if(preorder[k]>parent.val){
                right=k;
                break;
            }
        }
        if(preorder[i]<parent.val) parent.left=new TreeNode1008(preorder[i]);
        if(preorder[right]>parent.val) parent.right=new TreeNode1008(preorder[right]);
        buildTree(preorder, i+1, (right!=i)?right-1:j,parent.left);
        buildTree(preorder,(right==i)?i+1:right+1, j, parent.right);
    }
    public TreeNode1008 bstFromPreorder(int[] preorder) {
        TreeNode1008 root=new TreeNode1008(preorder[0]);
        buildTree(preorder, 1, preorder.length-1, root);
        return root;
    }
}
public class P1008 {
    public static void main(String[] args) {
        
    }
}
