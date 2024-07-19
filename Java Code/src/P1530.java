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
    private int result=0;
    private final int MaxDist = 10;
    private int[] traversal(TreeNode node,int distance){
        if(node==null) return new int[MaxDist+1];
        if(node.left==null && node.right==null){
            int[] res = new int[MaxDist+1];
            res[1]=1;
            return res;
        }
        int[] left = traversal(node.left, distance);
        int[] right = traversal(node.right, distance);
        for(int i=1;i<=distance;i++)
            for(int j=1;j<=distance-i;j++)
                result+=left[i]*right[j];
    
        int[] res = new int[MaxDist+1];
        for(int i=1;i<MaxDist;i++)
            res[i+1]=left[i]+right[i];
        return res;
    }
    public int countPairs(TreeNode root, int distance) { // count good pairs
        traversal(root, distance);
        return result;
    }
}
public class P1530 {
    public static void main(String[] args) {
        
    }
}
