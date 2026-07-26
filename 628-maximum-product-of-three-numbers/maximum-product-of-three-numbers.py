class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        a = b = c = -1001 # 3 maximum, a is largest
        x = y = 1001 # 2 minimum, x is smallest

        for n in nums:

            # recurisvely update 3 maximum
            if n > a:
                c = b
                b = a
                a = n
            elif n > b:
                c = b
                b = n
            elif n > c:
                c = n

            # recursively update 2 minimum
            if n < x:
                y = x
                x = n
            elif n < y:
                y = n
        
        return max(a * b * c, a * x * y)
                