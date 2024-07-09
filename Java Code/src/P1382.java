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
class Solution{
    private TreeNode TreeBuilder(List<TreeNode> array,int start,int end){
        if(start>end) return null;
        // 1,2,3,4,5,6,|7|,8,9,10,11,12
        int mid=start+(end-start)/2;
        TreeNode node=array.get(mid);
        node.left=TreeBuilder(array, start, mid-1);
        node.right=TreeBuilder(array, mid+1, end);
        return node;
    }
    private void tree2Array(TreeNode node,List<TreeNode> list){
        if(node==null) return;
        tree2Array(node.left, list);
        list.add(node);
        tree2Array(node.right, list);
    }
    public TreeNode balanceBST(TreeNode root) {
        List<TreeNode> list= new ArrayList<>();
        tree2Array(root, list);
        Comparator<TreeNode> myComparator= (TreeNode left, TreeNode right)->{
            return left.val-right.val;
        };
        list.sort(myComparator);
        return TreeBuilder(list, 0, list.size()-1);
    }
}
