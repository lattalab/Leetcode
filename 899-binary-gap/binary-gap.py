class Solution:
    def binaryGap(self, n: int) -> int:
        first_one = False
        pos = 0
        cur = 0
        ans = 0
        while n:
            if (n & 1) == 1:
                if first_one:
                    ans = max(ans, cur - pos)

                first_one = True
                pos = cur
                
            # update bit position
            cur += 1
            # update n
            n >>= 1
        
        return ans