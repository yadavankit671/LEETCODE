using System;
using System.Globalization;
using System.Numerics;
namespace Sorted_array_to_BST{
    public class TreeNode {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    public class Solution {
        public TreeNode SortedArrayToBST(int[] nums) {
            if (nums.Length==0) return null;
            if (nums.Length==1) return (new TreeNode (nums[0]));
            int middle=nums.Length/2;
            TreeNode root=new TreeNode(nums[middle]);
            int[] left=new int[middle];
            int[] right = new int[middle];
            for(int i=0;i<middle;i++)
            left[i]=nums[i];
            int j=0;
            for(int i=middle+1;i<nums.Length;i++)
            right[j++]=nums[i];
            root.left=SortedArrayToBST(left);
            root.right=SortedArrayToBST(right);
            return root;
        }
        

    }
}