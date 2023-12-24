"""
PROBLEM:
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths
where the sum of the node values in the path equals targetSum. Each path should be
returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node.
A leaf is a node with no children.
"""
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
    
class Solution:
    # preorder search
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        # if tree is empty
        if not root: return []

        # if targetsum found and current node is a leaf node
        if root.val == targetSum and not root.left and not root.right: return [[root.val]]

        # paths
        sums = []

        # check if left node exists
        if root.left:
            # traverse left subtree
            res = self.pathSum(root.left, targetSum-root.val)
            if res:
                for path in res:
                    # add all valid paths to list
                    sums.append([root.val] + path)

        # check if node exists
        if root.right:
            # traverse right subtree
            res = self.pathSum(root.right, targetSum-root.val)
            if res:
                for path in res:
                    # add all valid paths to list
                    sums.append([root.val] + path)
        return sums