class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0: return 0
        if x == 1: return 1
        return int(x**0.5)