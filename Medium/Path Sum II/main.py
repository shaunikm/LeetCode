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
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if not root: return []
        print(f"Traversed to: {root.val}")
        sums = []
        if root.left:
            if root.left.val == targetSum: sums.append([root.val] + [root.left.val])
            if root.left.val < targetSum:
                res = self.pathSum(root.left, targetSum-root.val)
                if res:
                    for path in res:
                        sums.append([root.val] + path)
        if root.right:
            if root.right.val == targetSum: sums.append([root.val] + [root.right.val])
            if root.right.val < targetSum:
                res = self.pathSum(root.right, targetSum-root.val)
                if res:
                    for path in res:
                        sums.append([root.val] + path)
            