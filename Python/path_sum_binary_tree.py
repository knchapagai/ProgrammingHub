# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self, node, cur_sum, target_sum):
        if node:
            if not node.left and not node.right and cur_sum + node.val == target_sum:
                return True
        
            return self.traversal(node.left, cur_sum + node.val, target_sum) or self.traversal(node.right, cur_sum + node.val, target_sum)
        
        return False
        
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        
        return self.traversal(root, 0, targetSum)
