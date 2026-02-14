class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        # initial stack for left wall
        stack = []
        for idx in range(len(height)):
            # if stack is empty, insert new left wall
            if not stack:
                stack.append(idx)
            # if stack is not empyt, and current height > stack.top()
            # we find Wall of Right side
            while stack and height[idx] > height[stack[-1]]:
                # current dealt height
                bottom = height[stack.pop()]

                # no one can stand for left Wall
                if not stack: 
                    break

                # calculate water by layer of height
                width = idx - stack[-1] - 1
                bounded_height = min(height[stack[-1]], height[idx]) - bottom
                ans += bounded_height * width
            
            # push new left wall
            stack.append(idx)

        return ans
