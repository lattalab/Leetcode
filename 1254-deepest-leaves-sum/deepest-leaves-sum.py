# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        from collections import deque
        q = deque([root])

        while q:    # 相當於檢查 q 是否為空
            size = len(q)   # 得知目前 q 還有多少元素
            ans = 0
            for _ in range(size):
                node = q.popleft()  # 從左端 pop 出並得到值
                ans += node.val # 將這層的值紀錄
                # 如果有 child 則放入 deque，trace 下一層 (while)
                if node.left: 
                    q.append(node.left)
                if node.right: 
                    q.append(node.right)

        return ans