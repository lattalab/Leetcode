# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def solve(root, ans: List[int]):
    if root == None: return

    ans.append(root.val)
    solve(root.left, ans)
    solve(root.right, ans)

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        solve(root, ans)
        return ans