# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathsum(self, root, num):
        if root == None:
            return 0

        cur = num * 2 + root.val
        if root.left == None and root.right == None:
            return cur

        left = self.pathsum(root.left, cur)
        right = self.pathsum(root.right, cur)
        return left + right

    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        return self.pathsum(root, 0)