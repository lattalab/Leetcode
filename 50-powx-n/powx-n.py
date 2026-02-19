class Solution:
    def myPow(self, x: float, n: int) -> float:
        
        # helper function
        def quickPow(x: float, n: int) -> float:
            # edge case
            if n == 0:
                return 1
            
            if (n%2 == 0):
                return quickPow(x*x, n//2)
            return x * quickPow(x, n-1)

        # main function
        ans = quickPow(x, abs(n))
        if (n >= 0):
            return ans
        return 1.0/ans
        
        