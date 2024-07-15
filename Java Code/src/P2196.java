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
import java.util.*;
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> nodeMap = new HashMap<>();
        for (int[] desc : descriptions) {
            int parentVal = desc[0], childVal = desc[1], isLeft = desc[2];
            TreeNode parent = nodeMap.computeIfAbsent(parentVal, TreeNode::new);
            TreeNode child = nodeMap.computeIfAbsent(childVal, TreeNode::new);
            if (isLeft == 1) parent.left = child;
            else parent.right = child;
        }
        for (int[] desc : descriptions) nodeMap.remove(desc[1]); 
        return nodeMap.values().iterator().next();
    }
}
public class P2196 {

}
