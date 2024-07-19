import java.util.*;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private TreeNode solve(TreeNode node,Set<Integer> st,List<TreeNode> result, boolean push){
        if(node == null) return null;
        boolean delete = st.contains(node.val);
        if(push && !delete) result.add(node);
        node.left = solve(node.left,st,result,delete);
        node.right = solve(node.right,st,result,delete);
        return delete ? null : node;
    }
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        List<TreeNode> res = new ArrayList<>();
        Set<Integer> st = new HashSet<>();
        for(int x : to_delete) st.add(x);
        solve(root,st,res,true);
        return res;
    }
}
public class P1110 {

}
