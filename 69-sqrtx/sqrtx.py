class Solution:
    def mySqrt(self, x: int) -> int:
        left = 1
        right = x

        # python didn;t have overflow issue
        while left <= right:
            mid = (left + right) // 2
            if (mid * mid > x):
                right = mid -1
            elif (mid * mid < x):
                left = mid + 1
            else:
                return mid
    
        return left - 1